#include "main_header.h"

int my_exit(char *exe, char **argvec, int n, int *exit_stat)
{
    char *err_num;/*to be freed*/
    char *err_msg;
    char *err_msg2;
    if (argvec[1] != NULL)
    {
    if (str_to_int(argvec[1]) == -1)
    {
    err_num = int_to_str(n);/*to be freed*/
    err_msg = concat_all(4, exe + 2, ": ", err_num, " exit:");/*to be freed*/
    err_msg2 = concat_all(4, err_msg, " Illegal number: ", argvec[1], "\n");/*to be freed*/
    write(STDERR_FILENO, err_msg2, my_strlen(err_msg2));
    free(err_num);
    free(err_msg);
    free(err_msg2);
    *exit_stat = 2;
    return (0);
    }
    }
    else
    return (1);
}

/**
 * my_wait - wait any child process
 * Return: the exit status of the child process
 */
int my_wait()
{
int status, exit_stat;
wait(&status);
if (WIFEXITED(status))
{
exit_stat = WEXITSTATUS(status);
}
return (exit_stat);
}

/**
 * execute_command - execute a command
 * @clr_line: the line stripped of spaces
 * @exe: the excutable
 * @env: the environment variable
 * @n: the nth time to show the prompt
 * @is_ex: is the command passed "exit"
 * Return: the exit status of the child process
 */
int execute_command(char *clr_line, char *exe, char **env, int n, int *is_ex)
{
char **argvec = split_args(clr_line); /* to be freed*/
char *path = my_get_env("PATH", env);
char **dirs_arr = split_path(path);/*to be freed*/
char *com_full_path = search_command(argvec[0], dirs_arr), *old_command;
int exit_stat = 0;
pid_t pid = 1;
if (my_strncmp(argvec[0], "exit", my_strlen(argvec[0])) == 1)
*is_ex = my_exit(exe, argvec, n, &exit_stat);
if (com_full_path != NULL)
{
pid = fork();
if (pid == 0)
{
execve(com_full_path, argvec, env);
perror("execve");/*to be looked up*/
exit(EXIT_FAILURE);
}
else
exit_stat = my_wait();
}
else if ((com_full_path == NULL) && (*is_ex < 0))
{
print_error(exe + 2, argvec[0], n);
exit_stat = 127;
}
free_double_ptr(argvec);
free_double_ptr(dirs_arr);
free(clr_line);
free(com_full_path);
return (exit_stat);
}
