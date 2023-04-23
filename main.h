#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdef.h>
#include <string.h>

/**
 * struct pr - struct for operations
 * @op: operation
 * @f: to be listed
 * Description: Checks if there's an operation
 */
typedef struct pr
{
	char *op;
	int (*f)(va_list);
} prf;

int _putchar(char c);
int _printf(const char *format, ...);
int _funcopr(const char *format, prf opr[], va_list list);
int print_c(va_list list);
int print_s(va_list list);
int print_mod(va_list list);

#endif
