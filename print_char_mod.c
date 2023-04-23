#include "main.h"


/**
 * print_char - Prints a chararter
 * @types: arguments that will be used to print the character
 *
 * @buffer: buffer array used to handle the print
 *
 * @width: integer specifies the width of output
 *
 * @flags: stores information about which flags active
 * 
 * @precision: integer specifies precision of output
 *
 * @size: Size
 *
 * Return: result
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}


/**
 * print_string - function prints a string
 * @types: arguments that will be used to print the character
 *
 * @buffer: buffer array used to handle the print
 *
 * @width: integer specifies the width of output
 *
 * @flags: stores information about which flags active
 * 
 * @precision: integer specifies precision of output
 *
 * @size: Size
 *
 * Return: result
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int s, length = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (s = width - length; s > 0; s--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (s = width - length; s > 0; s--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent -  function for printing percent signs
 * @types: arguments that will be used to print the character
 *
 * @buffer: buffer array used to handle the print
 *
 * @width: integer specifies the width of output
 *
 * @flags: stores information about which flags active
 * 
 * @precision: integer specifies precision of output
 *
 * @size: Size
 *
 * Return: result
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_int - function prints integer
 * @types: arguments that will be used to print the character
 *
 * @buffer: buffer array used to handle the print
 *
 * @width: integer specifies the width of output
 *
 * @flags: stores information about which flags active
 * 
 * @precision: integer specifies precision of output
 *
 * @size: Size
 *
 * Return: result
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int l = va_arg(types, long int);
	unsigned long int num;

	l = convert_size_number(l, size);

	if (l == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)l;

	if (l < 0)
	{
		num = (unsigned long int)((-1) * l);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - function prints a binary
 * @types: arguments that will be used to print the character
 *
 * @buffer: buffer array used to handle the print
 *
 * @width: integer specifies the width of output
 *
 * @flags: stores information about which flags active
 * 
 * @precision: integer specifies precision of output
 *
 * @size: Size
 *
 * Return: result
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, n, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	n = 2147483648;
	a[0] = b / n;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (b / n) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
