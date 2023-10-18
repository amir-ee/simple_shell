#include "main.h"

int cheacking_if_beild_in_func(char **args, int *hold_on, char *argv, int indx, char **pnt2, char ***env_adrrses, int *env_counter, char **pwd2, int *cd_cn2, char ***dirctures_two2, char **path_f_time2, int *c_cd_adv2, int *cn_null2, char **home_path2)
{
    char *beild_in_func[] = {"exit", "env", "setenv", "cd", NULL};
    int i = 0;
    char **new_env_adrrses;

    for (i = 0; beild_in_func[i] != NULL; i++)
    {
        if (_cmp(args[0], beild_in_func[i]) == 0)
        {
            if (_cmp(args[0], "exit") == 0)
            {
                _simpel_exit(hold_on, args, argv, indx, env_adrrses);
                return (1);
            }
            else if (_cmp(args[0], "env") == 0)
            {
                free_2d_1(args);
                _display_env_var();
                *hold_on = 0;
                return (1);
            }
            else if (_cmp(args[0], "setenv") == 0)
            {

                if (args[1] == NULL)
                {
                    free_2d_1(args);
                    *hold_on = 0;
                    return (1);
                }
                else if (args[2] == NULL)
                {
                    free_2d_1(args);
                    *hold_on = 0;
                    return (1);
                }
                else if (args[3] == NULL)
                {
                    z_setenv(args[1], args[2], pnt2);
                    free_2d_1(args);
                    *hold_on = 0;
                    (*env_counter)++;

                    /* allocing memory for env adreses so we can free theme easy */
                    new_env_adrrses = (char **)realloc(*env_adrrses, (*env_counter + 1) * sizeof(char *));
                    *env_adrrses = new_env_adrrses;
                    (*env_adrrses)[(*env_counter) - 1] = *pnt2;
                    (*env_adrrses)[(*env_counter)] = NULL;
                    return (1);
                }
                else if (args[3] != NULL)
                {
                    /* eror */
                    free_2d_1(args);
                    z_p_erore_env();
                    *hold_on = 2;
                    return (1);
                }
            }
            else if (_cmp(args[0], "cd") == 0)
            {
                zz_cd(args, pwd2, cd_cn2, dirctures_two2, path_f_time2, c_cd_adv2, cn_null2, home_path2, argv, indx);
                free_2d_1(args);
                *hold_on = 0;
                return (1);
            }
        }
    }
    return (0);
}
