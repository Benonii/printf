#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * unsigned_integer - prints unsigned integers
 * @args: List of arguments
 *
 * Return: count of the numbers
 */

int unsigned_integer(va_list args)
{
	unsigned int n;

	n = va_arg(args, unsigned int);

	if (n == 0)
	{
		return (print_unsigned_no(n));
	}
	if (n < 1)
	{
		return (-1);
	}
	return (print_unsigned_no(n));
}

/**
 * print_unsigned_no - prints an unsigned number
 *
 * @m: unsigned integer
 * Return: amount of numbers printed
 */

int print_unsigned_no(unsigned int m)
{
	int y = 1, z = 0;

	unsigned int num;

	num = m;

	for (; num / y > 9; )
	{
		y *= 10;
	}
	for (; y != 0; )
	{
		z += _write((num / y) + '0');

		num %= y;

		y /= 10;
	}

	return (z);
}
