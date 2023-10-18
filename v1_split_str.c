#include "main.h"

void _looping(char ***args, int *arg_count, int *arg_capacity,
char ***new_args, char *text, char **token);

/**
 * _split_str - Splits a string into an array of tokens.
 * @text: The input string to be split.
 *
 * This function splits the input string into an array of tokens using
 * whitespace characters as delimiters.
 *
 * Return: An array of token strings, or NULL if an error occurs.
 */

char **_split_str(char *text)
{
	char *token;
	char **args;
	char **new_args;
	int arg_count;
	int arg_capacity;

	switch (!text)
	{
	case 1:
		return (NULL); /* Code to execute when text is NULL */
	default:
		/* Code to execute when text is not NULL */
		break;
	}

	token = strtok(text, " \t\n");
	switch (token == NULL)
	{
	case 1:
		free(text);
		text = NULL;
		return (NULL);
	default:
		/* Code to execute when token is not NULL */
		break;
	}

	/* creating array  to store @text var as args */
	args = NULL;
	arg_count = 0;
	arg_capacity = 10;

	args = (char **)malloc(arg_capacity * 8); /* 8 = sizeof(char *) */

	/* CHEACK IF malloc IS NULL */
	switch (args == NULL)
	{
	case 1:
		perror("malloc");
		free(text);
		text = NULL;
		return (NULL);
	default:
		/* Code to execute when args is not NULL */
		break;
	}

	_looping(&args, &arg_count, &arg_capacity, &new_args, text, &token);

	if (text != NULL)
	{
		free(text);
		text = NULL;
	}

	return (args);
}

/**
 * _looping - Helper function to loop through the input string and tokenize it.
 * @args: A pointer to the array of token strings.
 * @arg_count: A pointer to the count of tokens.
 * @arg_capacity: A pointer to the capacity of the token array.
 * @new_args: A pointer to the new token array.
 * @text: The input string.
 * @token: A pointer to the current token.
 *
 * This function loops through the input string, tokenizes it, and dynamically
 * resizes the token array as needed.
 */

void _looping(char ***args, int *arg_count, int *arg_capacity,
char ***new_args, char *text, char **token)
{
	do {
		switch ((*arg_count) >= (*arg_capacity))
		{
		case 1:
			/* Resize the array if the user enters more than 10 (*args) */
			(*arg_capacity) *= 2;			/* 8 = sizeof(char *) */
			(*new_args) = (char **)realloc((*args), (*arg_capacity) * 8);
			/* malloc failed */
			switch ((*new_args) == NULL)
			{
			case 1:
				free(text);
				text = NULL;
				free_2d_1((*args));
				return;

			default:
				/* Default case if new_(*args) is not NULL */
				break;
			}

			(*args) = (*new_args);
			break;

		default:
			/* Default case if (*arg_count) < (*arg_capacity) */
			break;
		}

		(*args)[(*arg_count)++] = str_copy((*token));

		(*token) = strtok(NULL, " \t\n");
	} while ((*token) != NULL);

	/* setting (null) at befor the last index of (*args) */
	(*args)[(*arg_count)] = NULL;
}
