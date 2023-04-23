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
		count = _funcopr(format, opr, list);
		va_end(list);
	}
}

/**
 * _funcopr - Helper function to print and call functions.
 * @format: String recieved.
 * @opr: special options.
 * @list: arguments
 * Return: number of chars printed
 */

int _funcopr(const char *format, prf opr[], va_list list)
{
	int count = 0, x, y;

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0')
			{
				return (-1);
			}
			for (y = 0; ops[y].op != NULL; y++)
			{
				if (format[x + 1] == ops[y].op[0])
				{
					count = count + ops[y].f(list);
					break;
				}
			}
			if (opr[y].op == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					_putchar(format[x]);
					_putchar(format[x + 1]);
					count = count + 2;
				}
				else
					return (-1);
			}
			x = x + 1;
		}
		else
		{
			_putchar(format[x]);
			count = count + 1;
		}
	}
	return (count);
}
