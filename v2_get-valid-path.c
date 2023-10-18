#include "main.h"

char *get_valid_path(char *command)
{
    /* check if command is path / */

    /*___________________________________________________*/
    /* VAR */
    int skiip = 0;
    char *chek_path;
    char *lola;
    char *final_path;
    char *pathili;

    int i = 0;
    struct stat st;
    /* VAR */

    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
            {
                return (str_copy(command));
            }
            else
            {
                return (NULL);
            }
        }
    }
    pathili = my_z_get_env_z("PATH");
    if (!pathili)
    {
        return (NULL);
    }

    /*___________________________________________________*/

    /* if command is not a path */
    if (skiip != 1)
    {
        /* Check if PATH is not NULL */

        lola = str_copy(pathili);

        /* IF lola NOT FOUND */
        if (lola == NULL)
        {
            return (NULL);
        }

        /*  check if the file exiest */
        final_path = NULL;

        chek_path = strtok(lola, ":");

        while (chek_path != NULL)
        {
            struct stat info;
            final_path = _assemble(chek_path, command);

            if (final_path == NULL)
            {
                perror("malloc");
                free(lola);
                return NULL;
            }

            if (stat(final_path, &info) == 0)
            {
                /* !!!!!! file exist */

                free(lola);
                free(pathili);
                return (final_path);
            }
            free(final_path);
            chek_path = strtok(NULL, ":");
        }
        free(pathili);
        free(lola);
        return (NULL);
    }
    /* if command is path  */
    else
    {
        struct stat info;
        if (stat(command, &info) == 0)
        {
            /* !!!!!! file exist */
            return str_copy_const(command);
        }
        /* IF PATH NOT FOUND */
        else
        {
            return (NULL);
        }
    }
}
