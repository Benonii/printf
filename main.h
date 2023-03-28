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
int print_percent(va_list args);
int print_pointer(va_list args);
int print_binary(va_list args);
void recursion_binary(int a);
int unsigned_integer(va_list args);
int print_unsigned_no(unsigned int m);
int if_null(void);

/**
 * struct printer - identifies format specifier
 * @symbol: char
 * @print: to be printed
 *
 * Return: pointer
 */

typedef struct printer
{
	char *symbol;
	int (*print)(va_list arg);
} print;

#endif
