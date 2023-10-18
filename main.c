#include "main.h"

int main(int argc, char **argv)
{
    int True = 1;
    char *text = NULL;
    char **args = NULL;
    char *name_program = argv[0];

    /* status exe */
    int hold_on = 0;
    int count_loop = 0;

    /* im big pointing */
    char *pnt1 = NULL;
    char **env_adrrses = NULL;
    int env_counter = 0;
    int ol = 0;

    /* cd */
    char *pwd = NULL;
    int cd_cn = 0;
    char **dirctures_two = NULL;
    char *path_f_time = NULL;
    int c_cd_adv = 0;
    int cn_null = 0;
    char *home_path = NULL;

    (void)argc;

    while (True)
    {

        count_loop++;
        text = display_AND_get_line();
        new_line_and_status(text);

        if (text == NULL) /* EOF */
        {
            if (env_adrrses != NULL)
            {
                while (env_adrrses[ol] != NULL)
                {
                    free(env_adrrses[ol]);
                    ol++;
                }
                free(env_adrrses);
            }
            if (pwd != NULL)
            {
                free(pwd);
            }
            if (path_f_time != NULL)
            {
                free(path_f_time);
            }
            if (dirctures_two != NULL)
            {
                free(dirctures_two);
            }
            if (home_path != NULL)
            {
                free(home_path);
            }

            return (hold_on);
        }

        /* zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz */

        if (z_check_others(text, argv[0], &hold_on, &text))
        {
            free(text);
            text = NULL;
            continue;
        }

        /* zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz */

        args = _split_str(text); /* text will be free here */

        if (args == NULL)
        {
            continue;
        }

        if (cheacking_if_beild_in_func(args, &hold_on, argv[0], count_loop, &pnt1, &env_adrrses, &env_counter, &pwd, &cd_cn, &dirctures_two, &path_f_time, &c_cd_adv, &cn_null, &home_path))
        {
            /* pnt1 = NULL; */
        }
        else
        {
            hold_on = my_z_executing_func(args, name_program, count_loop);
        }
    }

    return (0);
}
