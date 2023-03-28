#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * _write - writes the character c to stdout
 * @c: character to print
 * Return: 1 or -1
 */

int _write(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_stdo - writes characters on standard output
 *
 * @s: string
 *
 * return (0);
 */

void write_stdo(char *s)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_write(str[i]);
	}
}

/**
 * len_base - calculates the length of an octal no
 *
 * @num: the no to calculate for length
 *
 * @base: calculating base
 *
 * Return: length of num
 */

unsigned int len_base(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * rev_string - reverses a string
 *
 * @s: string to reverse
 * Return: pointer
 */

char *rev_string(char *s)
{

