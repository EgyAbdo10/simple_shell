#include "main_header.h"
/**
 * split_args - split arguments and save them in an array
 * @line: the line to split
 * Return: double pointer to a the spiltted arguments
 */
char **split_args(char *line)
{
char **argvec = NULL;
char *line_copy, *line_copy2;
char *iter1, *iter2;
int num_args = 0;
if (my_strlen(line) <= 0)
return (NULL);
line_copy = my_strdup(line);
line_copy2 = my_strdup(line);
iter1 = strtok(line_copy, " ");
for (; iter1 != NULL; num_args++)
{
iter1 = strtok(NULL, " ");
}
argvec = malloc(sizeof(char *) * (num_args + 1));
iter2 = strtok(line_copy2, " ");
for (num_args = 0; iter2 != NULL; num_args++)
{
argvec[num_args] = my_strdup(iter2);
iter2 = strtok(NULL, " ");
}
argvec[num_args] = NULL;
free(line_copy);
free(line_copy2);
return (argvec);
}
/**
 * free_double_ptr - free memory pointed to by a double pointer
 * @argvec: the double pointer
 */
void free_double_ptr(char **argvec)
{
int i = 0;
if (argvec == NULL)
return;
for (; argvec[i] != NULL; i++)
{
free(argvec[i]);
}
free(argvec);
}
