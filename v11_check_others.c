#include "main.h"

int z_check_others(char *text, char *argv, int *hold_on, char **text_nw)
{
    int i;
    int len_tx;
    int l = 0;

    len_tx = _len_char(text);

    for (i = 0; i < len_tx; i++)
    {
        if (text[i] == ';')
        {
            l = my_z_separator(text, argv, hold_on);
            if (l == 3)
            {
                (*text_nw) = (char *)realloc((*text_nw), (len_tx - 1));
                (*text_nw)[(len_tx - 2)] = '\0';

                return(0);
            }
            return (1);
        }
    }
    return (0);
}