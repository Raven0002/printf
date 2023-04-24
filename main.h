#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: format
 * @f: function
 */
struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - format structure
 *
 * @fmt: format
 * @fm_t: function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

#endif
