#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);

typedef struct printer
{
	char *symbol;
	int (*print)(va_list arg);
} print;

#endif
