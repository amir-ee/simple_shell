#include "main.h"

int z_check_num(char *args)
{
    int arg_len, i;
    
    arg_len = _len_char(args);

    for (i = 0; i < arg_len; i++)
    {
        if (args[i] >= 48 && args[i] <= 57)
        {
            /* u look good 3 times zz */
        }
        else
        {
            return (-1);
        }
    }
    return (0);
}