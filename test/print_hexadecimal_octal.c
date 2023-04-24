#include "main.h"

/**
 * print_hexadecimal - function prints unsigned in hex char
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

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
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

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int o = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[o--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[o--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[o--] = '0';

	o++;

	return (write_unsgnd(0, o, buffer, flags, width, precision, size));
}
