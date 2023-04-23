#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdef.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

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
 * typedef struct fmt fmt_t - format structure
 *
 * @fmt:  string representing a format
 * @fm_t: function pointer
 */
typedef struct fmt fmt_t;

/**
 * struct fmt - Struct op
 *
 * @fmt: the format
 * @f: the function
 */
struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int);
};

int _putchar(char c);
int _printf(const char *format, ...);
int _funcopr(const char *format, prf opr[], va_list list);
void print_buffer(char buffer[], int *buff_ind);



int print_c(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_s(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_mod(va_list types, char buffer[],
		int flags, int width, int precision, int size);


#endif
