#include "main_header.h"
/**
 * my_exit - handle he exit command
 * @exe: the excutable
 * @argvec: the argument vector for the command line
 * @n: the nth time to show the prompt
 * @exit_stat: the exit status of the last command
 * Return: an indicator whether the exit is set or not
 */
int my_exit(char *exe, char **argvec, int n, int *exit_stat)
{
char *err_num;
char *err_msg;
char *err_msg2;
int exit_arg;
if (argvec[1] != NULL)
{
exit_arg = str_to_int(argvec[1]);
if (exit_arg < 0)
{
err_num = int_to_str(n);
err_msg = concat_all(4, exe, ": ", err_num, ": exit:");
err_msg2 = concat_all(4, err_msg, " Illegal number: ", argvec[1], "\n");
write(STDERR_FILENO, err_msg2, my_strlen(err_msg2));
free(err_num);
free(err_msg);
free(err_msg2);
*exit_stat = 2;
return (0);
}
else
{
*exit_stat = exit_arg;
return (2);
}
}
return (1);
}

/**
 * my_wait - wait any child process
 * Return: the exit status of the child process
 */
int my_wait(void)
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
char *com_full_path = search_command(argvec[0], dirs_arr);
int exit_stat = 0, is_env;
pid_t pid = 1;
if (my_strncmp(argvec[0], "exit", my_strlen(argvec[0])) == 1)
*is_ex = my_exit(exe, argvec, n, &exit_stat);
is_env = my_strncmp(argvec[0], "env", my_strlen(argvec[0]));
print_env(argvec, is_ex);
if ((com_full_path != NULL) && (is_env == 0))
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
print_error(exe, argvec[0], n);
exit_stat = 127;
}
free_double_ptr(argvec);
free_double_ptr(dirs_arr);
free(clr_line);
free(com_full_path);
return (exit_stat);
}
