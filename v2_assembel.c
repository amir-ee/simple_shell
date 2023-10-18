#include "main.h"

/**
 * _assemble - Combine a path and a command into a single string.
 * @path: The path string.
 * @command: The command string.
 *
 * This function combines the `path` and `command` strings with a separator
 * character '/' in between. It allocates memory for the result string and
 * returns it.
 *
 * Return: A pointer to the combined string, or NULL if memory allocat fails.
 */

char *_assemble(char *path, char *command)
{
	char separator = '/';
	int len_path = _len_char(path), len_command = _len_char(command);
	int total = len_path + 1 + len_command;
	char *assembled_path;
	int i_path = 0;
	int index = 0;
	AssembledPath *assembled_path_info = malloc(sizeof(AssembledPath));

	if (assembled_path_info == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	assembled_path_info->path = (char *)malloc(sizeof(char) * (total + 1));
	if (assembled_path_info->path == NULL)
	{
		free(assembled_path_info);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (i_path < len_path)
	{
		assembled_path_info->path[index] = path[i_path];
		i_path++;
		index++;
	}
	assembled_path_info->path[index] = separator;
	index++;
	i_path = 0;
	while (i_path < len_command)
	{
		assembled_path_info->path[index] = command[i_path];
		i_path++;
		index++;
	}
	assembled_path_info->path[index] = '\0';
	assembled_path_info->length = total;
	assembled_path = assembled_path_info->path;
	free(assembled_path_info);
	return (assembled_path);
}
