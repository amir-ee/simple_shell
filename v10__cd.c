#include "main.h"

int zz_cd(char **args, char **pwd3, int *cd_cn3, char ***dirctures_two3, char **path_f_time3, int *c_cd_adv3, int *cn_null3, char **home_path3, char *argv, int indx)
{
    int status_cd;

    int let_see = 0;
    char *messej = "can't cd to ";

    if ((*cd_cn3) == 0)
    {
        (*dirctures_two3) = (char **)malloc(3 * 8); /* 8 = sizeof(char *) */
        (*dirctures_two3)[2] = NULL;
    }

    if (args[1] == NULL)
    {

        if ((*cd_cn3) != 0)
        {
            free((*dirctures_two3)[0]);
            free((*dirctures_two3)[1]);
            *path_f_time3 = NULL;
            *pwd3 = NULL;
        }

        (*home_path3) = my_z_get_env_z("HOME"); /* malloc */

        *path_f_time3 = malloc(1024);
        (*dirctures_two3)[0] = (*home_path3);

        if ((*home_path3) != NULL)
        {
            status_cd = chdir((*home_path3));
        }

        if (status_cd == 0)
        {

            *pwd3 = malloc(1024);
            getcwd(*pwd3, 1024);

            if ((*cd_cn3) >= 0)
            {
                (*dirctures_two3)[1] = (*pwd3);
            }

            (*cd_cn3) = (*cd_cn3) + 1;
        }
        else if (status_cd == -1)
        {
            /* erors */
        }

        (*cn_null3) = (*cn_null3) + 1;
    }
    else if (strcmp(args[1], "-") == 0)
    {
        /* write(2, *pwd3, 1024); */ /* __ */

        if ((*cd_cn3) == 0)
        {
            (*home_path3) = my_z_get_env_z("PWD"); /* malloc */

            write(1, (*home_path3), _len_char((*home_path3)));
            write(1, "\n", 1);

            if ((*home_path3) != NULL)
            {
                free((*home_path3));
                (*home_path3) = NULL;
            }
            return (1);
        }

        if (((*c_cd_adv3) % 2) == 0)
        {
            if (access((*dirctures_two3)[0], F_OK) != -1)
            {
                if ((*dirctures_two3)[0] != NULL)
                {
                    status_cd = chdir((*dirctures_two3)[0]);
                }
                let_see = 1;
            }
        }
        else if (((*c_cd_adv3) % 2) == 1)
        {
            if (access((*dirctures_two3)[1], F_OK) != -1)
            {
                if ((*dirctures_two3)[1] != NULL)
                {
                    status_cd = chdir((*dirctures_two3)[1]);
                }
                let_see = 2;
            }
        }

        if (status_cd == 0)
        {
            if (let_see == 1)
            {
                write(1, (*dirctures_two3)[0], _len_char((*dirctures_two3)[0]));
                write(1, "\n", 1);
            }
            else if (let_see == 2)
            {
                write(1, (*dirctures_two3)[1], _len_char((*dirctures_two3)[1]));
                write(1, "\n", 1);
            }
        }
        else if (status_cd == -1)
        {
            /* erore */
        }

        (*c_cd_adv3) = (*c_cd_adv3) + 1;
    }
    else if (args[1] != NULL && args[2] == NULL)
    {
        if ((*cd_cn3) != 0)
        {
            free((*dirctures_two3)[0]);
            free((*dirctures_two3)[1]);
            *path_f_time3 = NULL;
            *pwd3 = NULL;
        }

        *path_f_time3 = malloc(1024);
        getcwd(*path_f_time3, 1024);

        (*dirctures_two3)[0] = (*path_f_time3);
        /* ......... */

        if (args[1] != NULL)
        {
            status_cd = chdir(args[1]);
        }

        if (status_cd == 0)
        {
            *pwd3 = malloc(1024);
            getcwd(*pwd3, 1024);

            if ((*cd_cn3) >= 0)
            {
                (*dirctures_two3)[1] = (*pwd3);
            }

            (*cd_cn3) = (*cd_cn3) + 1;
        }
        else if (status_cd == -1)
        {
            zz_p_eror_cd_zz(argv, indx, args, messej);
        }
        (*c_cd_adv3) = 0;
    }

    return (1);
}
