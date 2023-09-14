#include "main_header.h"
/**
 * print_env - print environmet variables
 * @argvec: the command line argumnet vector
 * @ex_st: a ponter to the exit status
 */
void print_env(char **argvec, int *ex_st)
{
char *err_msg1, *err_msg2;
int i;
char **env = environ;
if (my_strncmp(argvec[0], "env", my_strlen(argvec[0])) == 1)
{
if (argvec[1] != NULL)
{
err_msg1 = concat_all(2, "env: ‘", argvec[1]);
err_msg2 = concat_all(2, err_msg1, "’: No such file or directory\n");
write(STDERR_FILENO, err_msg2, my_strlen(err_msg2));
free(err_msg1);
free(err_msg2);
*ex_st = 127;
}
else
{
for (i = 0; env[i] != NULL; i++)
{
write(STDOUT_FILENO, env[i], my_strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
}
}
}
}
