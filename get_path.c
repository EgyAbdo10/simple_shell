#include "main_header.h"
/**
 * my_get_env - get environment variables values
 * @var: the environment variable
 * @env: a pointer to the environment variables
 * Return: the environment variable value if found
 * or NULL if the variable not found
 */
char *my_get_env(char *var, char **env)
{
int i = 0;
char *env_var, *var_name;
for (; env[i] != NULL; i++)
{
env_var = my_strdup(env[i]);
var_name = strtok(env_var, "=");
if (my_strncmp(env_var, var, my_strlen(env_var)) == 1)
{
free(env_var);
return (my_strchr(env[i], '=') + 1);
}
else
free(env_var);
}
return (NULL);
}
/**
 * split_path - split a path into directories
 * @path: the path to split
 * Return: manually allocated array of diectories
 */
char **split_path(char *path)
{
int num_dirs = 0;
char **dirs_arr;
char *path_copy = my_strdup(path);
char *path_copy2 = my_strdup(path);
char *dir;
dir = strtok(path_copy, ":");
for (; dir != NULL; num_dirs++)
{
dir = strtok(NULL, ":");
}
dirs_arr = malloc(sizeof(char *) * (num_dirs + 1));
free(path_copy);
dir = strtok(path_copy2, ":");
for (num_dirs = 0; dir != NULL; num_dirs++)
{
dirs_arr[num_dirs] = my_strdup(dir);
dir = strtok(NULL, ":");
}
dirs_arr[num_dirs] = NULL;
free(path_copy2);
return (dirs_arr);
}
