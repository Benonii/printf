#include <unistd.h>
#include "main.h"

/**
 * _write - writes the character c to stdout
 * @c: character to print
 * Return: 1 or -1
 */

int _write(char c)
{
        return (write(1, &c, 1));
}
