#include "main.h"

ssize_t _my_z_get_line(char **lineptr, size_t *n, int fd)
{
    char c;       /* Temporary character storage. */
    size_t i = 0; /* Index for writing characters into the line buffer. */
    ssize_t read_result;

    /* Check if the line buffer is uninitialized or too small. */
    if (*lineptr == NULL || *n == 0)
    {
        *n = 1024;                        /* Initial buffer size. */
        *lineptr = realloc(*lineptr, *n); /* Allocate memory. */

        if (*lineptr == NULL)
        {
            perror("realloc"); /* Handle memory allocation error. */
            return -1;
        }
    }

    /* Read characters from the file descriptor until a newline or EOF is encountered. */
    while ((read_result = read(fd, &c, 1)) > 0)
    {
        (*lineptr)[i++] = c; /* Store the character in the line buffer. */

        /* Check if the buffer is full, and if so, double its size. */
        if (i >= *n)
        {
            *n *= 2;                          /* Double the buffer size. */
            *lineptr = realloc(*lineptr, *n); /* Reallocate memory. */

            if (*lineptr == NULL)
            {
                perror("realloc"); /* Handle memory allocation error. */
                return -1;
            }
        }

        /* If a newline character is encountered, break the loop. */
        if (c == '\n')
        {
            break;
        }
    }

    if (read_result == 0 && i == 0) /* eof */
    {
        return -1;
    }

    (*lineptr)[i] = '\0'; /* Null-terminate the line. */

    return i; /* Return the number of characters read. */
}
