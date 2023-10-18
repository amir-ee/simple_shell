#include "main.h"

void _simpel_exit(int *hold_on, char **args, char *argv, int indx, char ***env_adrrses)
{
    int status_exit, check;
    char *messej = "Illegal number";
    int ol = 0;

    if (args[1] != NULL)
    {
        check = z_check_num(args[1]);
    }

    if (args[1] == NULL)
    {
        free_2d_1(args);

        if ((*env_adrrses) != NULL)
        {
            while ((*env_adrrses)[ol] != NULL)
            {
                free((*env_adrrses)[ol]);
                ol++;
            }
            free((*env_adrrses));
        }

        exit(*hold_on);
    }
    else if (args[1] != NULL && check == 0)
    {
        status_exit = z_arr_to_int(args[1]);

        if ((*env_adrrses) != NULL)
        {
            while ((*env_adrrses)[ol] != NULL)
            {
                free((*env_adrrses)[ol]);
                ol++;
            }
            free((*env_adrrses));
        }

        free_2d_1(args);
        exit(status_exit);
    }
    else
    {
        zz_p_eror_exit_zz(argv, indx, args, messej);
        free_2d_1(args);
        *hold_on = 2;
    }
}
