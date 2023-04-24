#include "main.h"

/**
 * print_hexadecimal - Prints unsigned number in hexadecimal notation
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
 * print_hexa - print lower hex chars
 * @types: arguments that will be used to print
 *
 * @map_to: map the hexadecimal value to the output
 *
 * @buffer: buffer array used to handle the print
 *
 * @flags: stores information about which flags active
 *
 * @flag_ch: stores additional information about active flags
 *
 * @width: integer specifies the width of output
 *
 * @precision: integer specifies precision of output
 *
 * @size: size
 *
 * Return: result
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
