#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * print_char - printd a single character
 * @args: The inputted char
 * Return: the number of chars printed(1)
 */

int print_char(va_list args)
{
	int n;
	char ch;
	char *nil;

	ch = va_arg(args, int);

	if (ch == '\0')
	{
		nil = "(null)";
		write(1, nil, 6);
		return (6);
	}
	else
	{
		n = write(1, &ch, 1);
		return (n);
	}
}

/**
 * print_string - prints a string
 * @args: The inputted string
 * Return: The numebr of chars printed
 */

int print_string(va_list args)
{
	char *str, *nil;
	int n;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		nil = "(null)";
		write(1, nil, 6);
		return (6);
	}
	else
	{
		n = write(1, str, strlen(str));
		return (n);
	}
}

/**
 * print_integer - prints an integer
 *
 * @args: a list of variadic arguments
 *
 * Return: length of the string
 */

int print_integer(va_list args)
{

	int count = 1, m = 0;

	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_write('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	recursion_integer(m);
	return (count);
}

/**
  * recursion_integer - Prints an integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void recursion_integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
	recursion_integer(t / 10);
	_write(t % 10 + '0');
}

/**
 * _printf - produces an output according to a format
 * @format: the format specifier
 * Return: The number of chars printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0, n = 0;
	char str[100] = {0};
	va_list args;

	print funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"u", unsigned_integer},
		{"p", print_pointer}
	};

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (format && format[i])
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			while (j < 7 && format[i] != *(funcs[j].symbol))
				j++;
			if (j < 7)
				n += funcs[j].print(args); }
		else
		{
			str[j] = format[i];
			k += write(1, str, strlen(str));
			j++;
		}
		i++;
	}
	return (k + n);
}
