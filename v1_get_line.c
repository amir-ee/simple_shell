#include "main.h"

/**
 * display_AND_get_line - Display prompt and read text from stdin
 *
 * Display "$ " if input is from a terminal and reads line of text from stdin.
 * Dynamically alloc memory for the input text which must be freed by caller.
 *
 * Return:
 * - NULL if end of file (EOF) is reached, and it frees the allocated memory.
 * - A pointer to the dynamically allocated input text for successful input,
 *   which the caller must free when no longer needed.
 */

char *display_AND_get_line(void)
{
	size_t text_len = 0;
	ssize_t read_result;
	char *text = NULL;

	/* displaying '$ ' __________________________ */
	switch (isatty(STDIN_FILENO))
	{
		case 1:
			write(1, "$ ", 2);
			break;
	}

	read_result = _my_z_get_line(&text, &text_len, 0);

	/* read line part ___________________________________________ */

	/* EOF PART */
	switch (read_result)
	{
		case END_OF_FILE:
			free(text);
			return (NULL);
		default:
			return (text);
	}
}
