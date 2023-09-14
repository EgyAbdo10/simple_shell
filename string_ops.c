#include "main_header.h"
/**
 * my_strlen - get the length of a string
 * @str: the string
 * Return: number of characters
*/
int my_strlen(char *str)
{
int i = 0;
if (str == NULL)
return (-1);
while (str[i] != '\0')
i++;
return (i);
}
/**
 * my_strdup - copy the content of a string into another bufffer
 * @str: the string
 * Return: the copied and manually allocated string string
*/
char *my_strdup(char *str)
{
int i = 0;
char *new_str;
if (str == NULL)
return (NULL);
new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
while (str[i] != '\0')
{
new_str[i] = str[i];
i++;
}
new_str[i] = '\0';
return (new_str);
}
/**
 * my_strchr - set the string pointer to a specific character
 * @str: the string
 * @chr: the character to point to
 * Return: a pointer to the character if found or null if not found
 */
char *my_strchr(char *str, char chr)
{
int i;
if (str == NULL)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] == chr)
return (str + i);
}
return (NULL);
}
/**
 * my_strncmp - compare first n characters of two strings
 * @str1: first strnig
 * @str2: second string
 * @n_chr: number of chars to be compared
 * Return: 1 if the first n chars of a string are the same
 * or 0 if they are different
 * or -1 on failure
 */
int my_strncmp(char *str1, char *str2, int n_chr)
{
int i;
if (str1 == NULL || str2 == NULL || n_chr < 1)
return (-1);
for (i = 0; i < n_chr; i++)
{
if (str1[i] != str2[i])
{
return (0);
}
}
return (1);
}
/**
 * my_strcat - concatenate two strings
 * @str1: first string
 * @str2: second string
 * Return: the concatenated string
 * or NULL on failure
 */
char *my_strcat(char *str1, char *str2)
{
int len;
int i, j;
char *new_str;
if (str1 == NULL || str2 == NULL)
return (NULL);
len = my_strlen(str1) + my_strlen(str2) + 1;
new_str = malloc(sizeof(char) * len);
for (i = 0; str1[i] != '\0'; i++)
{
new_str[i] = str1[i];
}
for (j = 0; str2[j] != '\0'; i++, j++)
{
new_str[i] = str2[j];
}
new_str[i] = str2[j];
return (new_str);
}
