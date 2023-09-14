#include "main_header.h"
/**
 * main - run a shell
 * @ac: number of arguments
 * @av: the argument vector
 * @env: a pointer to the env variables
 * Return: the exit status of the child process
 */
int main(int ac, char **av, char **env)
{
char *line = NULL, *clr_line = NULL;
int my_errno = 0, mode, is_exit = -1, last_status;
size_t bufsize = 0;
static int prompt_num = 1;
(void) ac;
while (1)
{
mode = isatty(STDIN_FILENO);
if (mode == 1)
write(STDOUT_FILENO, "$ ", 2);
if (getline(&line, &bufsize, stdin) == -1)
{
free(line);
if (mode == 1) write(STDOUT_FILENO, "\n", 1);
exit(my_errno);
}
line[my_strlen(line) - 1] = '\0';
clr_line = clear_spaces(line);
last_status = my_errno;
if (clr_line != NULL)
my_errno = execute_command(clr_line, av[0], env, prompt_num, &is_exit);
free(line);
if (is_exit == 1) exit(last_status);
if (is_exit == 2) exit(my_errno);
line = NULL;
prompt_num++;
}
return (my_errno);
}
