#include "main.h"

/**
 * free_2d_1 - Free a two-dimensional array of strings
 *
 * This function deallocates memory used by a two-dimensional array of strings
 * and sets the array and its elements to NULL to prevent double freeing.
 *
 * @im_2d_arr: The two-dimensional array of strings to be freed.
 *
 * Return: This function does not return a value.
 */

void free_2d_1(char **im_2d_arr)
{
	int c_free_args_1 = 0;

	switch (!im_2d_arr)
	{
		case 1:
			/* Code to execute when im_2d_arr is NULL */
			return;
		default:
			break;
	}
	do {
		free(im_2d_arr[c_free_args_1]);
		im_2d_arr[c_free_args_1] = NULL;
		c_free_args_1++;
	} while (im_2d_arr[c_free_args_1] != NULL);

	free(im_2d_arr);
	im_2d_arr = NULL;
}
