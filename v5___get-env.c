#include "main.h"

char *my_z_get_env_z(char *variable)
{
    char *tmp, *key, *value, *env;
    int i;

    for (i = 0; environ[i]; i++)
    {
        tmp = str_copy(environ[i]);
        key = strtok(tmp, "=");
        if (_cmp(key, variable) == 0)
        {
            value = strtok(NULL, "\n");
            if (value != NULL)
            {
                env = str_copy(value);
                free(tmp);
                return (env);
            }
            else
            {
                free(tmp);
                return (NULL);
            }
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
