#include "main_header.h"
/**
 * handle_comment - remove comments from a command
 * @line: the line containing the command
 * Return: a line free of comments
 */
char *handle_comment(char *line)
{
int len = my_strlen(line) - 1;
char *new_line = my_strdup(line);
if (new_line[0] == '#')
return (NULL);
for (; len >= 0; len--)
{
if (new_line[len] == '#' && new_line[len - 1] == ' ')
new_line[len - 1] = '\0';
}
return (new_line);
}
