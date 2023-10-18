#include "main.h"

char *my_z_strtok(char *str, const char *delim)
{
    /* Static pointer to the next token */
    static char *next_token = NULL;
    char *token;

    /* If str is NULL, we continue from where we left off */
    if (str == NULL)
    {
        str = next_token;
    }

    /* If str is NULL now, it means there are no more tokens */
    if (str == NULL)
    {
        return NULL;
    }

    /* Find the first character that is not a delimiter */
    str += strspn(str, delim);

    /* If we're at the end of the string, there are no more tokens */
    if (*str == '\0')
    {
        return NULL;
    }

    /* Find the end of the token */
    token = str;
    str = strpbrk(token, delim);

    /** If we found a delimiter, replace it with a null character
     * and save the position of the next character
     */
    if (str != NULL)
    {
        *str = '\0';
        next_token = str + 1;
    }
    else
    {
        next_token = NULL;
    }

    return token;
}
