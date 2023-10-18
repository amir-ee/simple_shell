#include "main.h"

void z_sprintf(char *ruslet, const char *str, const char *f_str, const char *s_str)
{
    int len_str;
    int len_f_str;
    int len_s_str;
    int i = 0, x = 0;

    int s_c = 0;

    int i1;

    len_str = stringLength_const_arr(str);
    len_f_str = stringLength_const_arr(f_str);
    len_s_str = stringLength_const_arr(s_str);

    for (; i < len_str; i++)
    {
        if (str[i] == '%' && str[i + 1] == 's')
        {
            i = i + 2;
            for (; x < len_f_str; x++)
            {
                *(ruslet + x) = f_str[x];
            }
            break;
        }
        else
        {
            *(ruslet + x) = str[i];
            x++;
        }
    }

    for (i1 = i; i1 < len_str; i1++)
    {
        if (str[i1] == '%' && str[i1 + 1] == 's')
        {
            i1 = i1 + 1;
            for (; s_c < len_s_str + 1; x++)
            {
                *(ruslet + x) = s_str[s_c];
                s_c++;
            }
        }
        else
        {
            *(ruslet + x) = str[i1];
            x++;
        }
    }
}
