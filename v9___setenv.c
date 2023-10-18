#include "main.h"

int z_setenv(const char *name, const char *value, char **pnt3)
{
    int i = 0;
    char *new_var;

    if (value == NULL)
    {
        value = "";
    }

    /* Check if the variable already exists and update it */
    while (environ[i] != NULL)
    {
        if (z_strncmp(environ[i], name, strlen(name)) == 0)
        {
            /* Update the existing variable */
            new_var = malloc(strlen(name) + strlen(value) + 2);
            z_sprintf(new_var, "%s=%s", name, value);
            environ[i] = new_var;

            *pnt3 = new_var;
            return 0;
        }
        i++;
    }

    /* If the variable doesn't exist, add a new one */
    new_var = malloc(strlen(name) + strlen(value) + 2);
    z_sprintf(new_var, "%s=%s", name, value);
    environ[i++] = new_var;
    environ[i] = NULL;

    *pnt3 = new_var;

    return 0;
}
