#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int my_z_separator(char *text, char *argv, int *hold_on)
{
    int i, x, o, p = 0;
    int len_tx;
    int break_point = 0;
    int confrm = 0;
    char *command = NULL;

    /* tools var*/
    char **args = NULL;
    char *name_program = argv;

    /* status exe */
    int count_loop = 0;
    int ol = 0;

    /* im big pointing */
    char *pnt1 = NULL;
    char **env_adrrses = NULL;
    int env_counter = 0;

    /* cd */
    char *pwd = NULL;
    int cd_cn = 0;
    char **dirctures_two = NULL;
    char *path_f_time = NULL;
    int c_cd_adv = 0;
    int cn_null = 0;
    char *home_path = NULL;

    len_tx = _len_char(text);

    for (i = 0; i < len_tx; i++)
    {
        if (text[i] == ' ' && text[i + 1] == ';' && text[i + 2] == ' ')
        {
            if (break_point == 0)
            {
                command = (char *)malloc((i + 1));
            }
            else
            {
                command = (char *)malloc((i) - (break_point - 1));
            }

            for (x = 0; x < (i - break_point); x++)
            {
                command[x] = text[break_point + x];
            }
            command[x] = '\0';

            /* ------------------------------------ */

            args = _split_str(command); /* text will be free here */

            if (args == NULL)
            {
                continue;
            }

            if (cheacking_if_beild_in_func(args, hold_on, argv, count_loop, &pnt1, &env_adrrses, &env_counter, &pwd, &cd_cn, &dirctures_two, &path_f_time, &c_cd_adv, &cn_null, &home_path))
            {
                /* secses */
            }
            else
            {
                *hold_on = my_z_executing_func(args, name_program, count_loop);
            }

            /* free */

            if (env_adrrses != NULL)
            {
                while (env_adrrses[ol] != NULL)
                {
                    free(env_adrrses[ol]);
                    ol++;
                }
                free(env_adrrses);
                env_adrrses = NULL;
            }
            if (pwd != NULL)
            {
                free(pwd);
                pwd = NULL;
            }
            if (path_f_time != NULL)
            {
                free(path_f_time);
                path_f_time = NULL;
            }
            if (dirctures_two != NULL)
            {
                free(dirctures_two);
                dirctures_two = NULL;
            }
            if (home_path != NULL)
            {
                free(home_path);
                home_path = NULL;
            }
            /* free */

            /* ------------------------------------ */

            break_point = (i + 3);
            i = break_point;
            confrm = 42;
        }
    }
    if (confrm == 42)
    {
        command = (char *)malloc((i) - (break_point - 1));

        for (o = break_point; text[o] != '\0'; o++)
        {
            command[p] = text[o];
            p++;
        }
        command[p] = '\0';

        /* ------------------------------------ */
        args = _split_str(command); /* text will be free here */

        if (args == NULL)
        {
            return (1);
        }

        if (cheacking_if_beild_in_func(args, hold_on, argv, count_loop, &pnt1, &env_adrrses, &env_counter, &pwd, &cd_cn, &dirctures_two, &path_f_time, &c_cd_adv, &cn_null, &home_path))
        {
            /* secses */
        }
        else
        {
            *hold_on = my_z_executing_func(args, name_program, count_loop);
        }

        /* free */

        if (env_adrrses != NULL)
        {
            while (env_adrrses[ol] != NULL)
            {
                free(env_adrrses[ol]);
                ol++;
            }
            free(env_adrrses);
            env_adrrses = NULL;
        }
        if (pwd != NULL)
        {
            free(pwd);
            pwd = NULL;
        }
        if (path_f_time != NULL)
        {
            free(path_f_time);
            path_f_time = NULL;
        }
        if (dirctures_two != NULL)
        {
            free(dirctures_two);
            dirctures_two = NULL;
        }
        if (home_path != NULL)
        {
            free(home_path);
            home_path = NULL;
        }
        /* free */

        /* ------------------------------------ */
    }
    else /* 1 semi colome */
    {
        return (3);
    }
    return (1);
}
