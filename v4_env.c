#include "main.h"

size_t custom_strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void _display_env_var()
{
    int i = 0;
    while (environ[i] != NULL)
    {
        write(1, environ[i], custom_strlen(environ[i]));
        write(1, "\n", 1);
        i++;
    }
}
