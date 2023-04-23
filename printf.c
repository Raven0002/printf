#include "main.h"

/**
 * _printf - Prints formatted string to standard output
 * @format: string containing zero or more directives
 * Return: result
 */
int _printf(const char *format, ...)
{
	int f, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (f = 0; format && format[f] != '\0'; f++)
	{
		if (format[f] != '%')
		{
			buffer[buff_ind++] = format[f];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &f);
			width = get_width(format, &f, list);
			precision = get_precision(format, &f, list);
			size = get_size(format, &f);
			++f;
			printed = handle_print(format, &f, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints contents of buffer
 * @buffer: Array of the chars
 * @buff_ind: Index where the next character should be added
 */
void print_buffer(char buffer[], int *buff_ind)
{
        if (*buff_ind > 0)
                write(1, &buffer[0], *buff_ind);

        *buff_ind = 0;
}
