#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdef.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct pr - struct for operations
 * @op: operation
 * @f: to be listed
 * Description: Checks if there's an operation
 */
typedef struct pr
{
	char op;
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
