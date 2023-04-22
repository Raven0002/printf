#include "main.h"

/**
 *_printf - is a function that prints
 *@format: gives the format to the function
 * cases -  c, s, %
 * Return: a string
 */

int _printf(const char *format, ...)
{
	va_list list;
	int count = -1;

	prf opr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_mod},
		{NULL, NULL}
	};

	if (format != NULL)
	{
		va_start(list, format);
		va_end(list);
	}
