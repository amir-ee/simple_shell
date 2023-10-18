#include "main.h"

/**
 * _len_char - Calculate the length of a string.
 * @tx: The input string.
 *
 * This function calculates the length of the input string by counting the
 * number of characters in it.
 *
 * Return: The length of the string.
 */

int _len_char(char *tx)
{
	int lx1 = 0;

	while (1)
	{
		switch (tx[lx1])
		{
			case '\0':
				/* The null terminator was found, exit the loop */
				goto exit_loop;

				break;
			default:
				lx1++;
				break;
		}
	}

exit_loop:

	return (lx1);
}
