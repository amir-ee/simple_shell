#include "main.h"

int z_strncmp(char *f_str,const char *s_str, int len_mx)
{
    int i;

    for (i = 0; i < len_mx; i++)
    {
        if (f_str[i] == s_str[i])
        {
            /* im soory */
        }
        else
        {
            return (-1);
        }
    }
    return (0);
}
