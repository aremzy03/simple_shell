#include "main.h"
/**
 *is_num - checks if a string is a number
 *@argv: the string to be checked
 *
 *Return: 0 on success and -1 on failure
 */
int is_num(char *argv)
{
	int i;

	for (i = 0; argv[i] != '\0'; i++)
	{
		if (isdigit(argv[i]) == 0)
			return (-1);
	}
	return (0);
}
/**
 *ptr_str - prints a string
 *@str: the string to be printed
 *
 *Return: always zero
 */
int ptr_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (0);
}
