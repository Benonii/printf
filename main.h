#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
void recursion_integer(int a);
int _write(char c);

typedef struct printer
{
	char *symbol;
	int (*print)(va_list arg);
} print;

#endif
