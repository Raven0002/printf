#include "main.h"

/**
 * print_c - print a character
 * @list: list
 * Return: a character
 */

int print_c(va_list list)
{
	char c;

	c = va_arg(list, int);
	_putchar(c);
	return (1);
}
/**
 * print_s - prints a string
 * @list: list
 * Return: a string
 */

int print_s(va_list list)
{
	int i;
	char *str2;

	str2 = va_arg(list, char *);

	if (str2 == NULL)
	{
		_printf("(null)");
		return (6);
	}
	for (i = 0; str2[i] != '\0'; i++)
		_putchar(str2[i]);
	return (i);
}
