#include "main_header.h"
/**
 * concat_all - concatenate all the strings passed
 * @argc: number of strings
 * Return: the manually allocated concatenated string
 */
char *concat_all(int argc, ...)
{
int i = 0;
char *new_str, *temp_str;
va_list args;
va_start(args, argc);
if (argc < 2)
return (NULL);
temp_str = my_strcat(va_arg(args, char *), "");
for (; i < (argc - 1); i++)
{
new_str = my_strcat(temp_str, va_arg(args, char *));
free(temp_str);
temp_str = new_str;
}
return (new_str);
}
