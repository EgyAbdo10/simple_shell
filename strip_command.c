#include "main_header.h"

/**
 * clear_spaces - strip text from spaces and tabs at first and end
 * @str: the string
 * Return: a manually allocated stripped string
*/
char *clear_spaces(char *str)
{
int i, len;
char *new_str, *new_str2;
if (str == NULL)
return (NULL);
if (str[0] == '\0')
return (NULL);
len = my_strlen(str) - 1;
while ((len >= 0) && ((str[len] == ' ') || (str[len] == '\t')))
len--;
if (len == -1)
return (NULL);
new_str = my_strdup(str);
new_str[len + 1] = '\0';
for (i = 0; (new_str[i] == ' ' || new_str[i] == '\t'); i++)
{};
new_str2 = my_strdup(new_str + i);
free(new_str);
return (new_str2);
}
