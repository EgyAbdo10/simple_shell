#include "main_header.h"
/**
 * power - raise a number to a power
 * @num: the number
 * @exp: the exponent
 * Return: the number raised to the given power
 */
int power(int num, int exp)
{
if (exp == 0)
return (1);
return (num * power(num, exp - 1));
}
/**
 * str_to_int - turn a string into a number
 * @str: the number as a string
 * Return: the number as an int
 * or -1 on error
 */
int str_to_int(char *str)
{
int number = 0, i, digit, is_neg = 0;
int len;
if (str == NULL)
return (-1);
if (str[0] == '-')
{
str += 1;
is_neg = 1;
}
len = my_strlen(str);
for (i = 0; str[i] != '\0'; i++, len--)
{
if (str[i] <= 57 && str[i] >= 48)
{
digit = str[i] - 48;
number += (digit *power(10, len - 1));
}
else
{
return (-1);
}
}
if (is_neg) number *= -1;
return (number);
}
/**
 * num_len - get the length of a number
 * @num: the number
 * Return: the number of digits in a number
 */
int num_len(int num)
{
int i;
for (i = 0; num != 0; i++)
{
num = num / 10;
}
return (i);
}
/**
 * int_to_str - turn an integer into a string
 * @number: the number as an integer
 * Return: the number as a string
 */
char *int_to_str(int number)
{
int len = num_len(number);
int temp_len = len - 1;
char *num_str = malloc(sizeof(char) * (len + 1));
int i;
for (i = 0; i < len; temp_len--, i++)
{
num_str[temp_len] = (number % 10) + 48;
number = number / 10;
}
num_str[len] = '\0';
return (num_str);
}
