#include "main.h"

/**
 * print_binary - function prints a binary
 * @types: arguments that will be used to print
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

/**
 * print_unsigned - print unsigned
* @types: arguments that will be used to print
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

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
