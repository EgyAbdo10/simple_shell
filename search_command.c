#include "main_header.h"
/**
 * search_command - search for a command in the path environment variable
 * @command: the command to search
 * @dirs_arr: the directories to search in
 * Return: the command full path if found
 * or NULL if not found
 */
char *search_command(char *command, char **dirs_arr)
{
int i;
struct stat st;
char *com_full_path;
if (stat(command, &st) == 0)
return (my_strdup(command));
command = my_strcat("/", command);
for (i = 0; dirs_arr[i] != NULL; i++)
{
com_full_path = my_strcat(dirs_arr[i], command);
if (stat(com_full_path, &st) != 0)
{
free(com_full_path);
}
else
{
free(command);
return (com_full_path);
}
}
free(command);
return (NULL);
}
