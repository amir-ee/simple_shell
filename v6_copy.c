#include "main.h"

void _copy_this_inside_this_and_my_z(char *tex1, char *tex2)
{
    int i = 0;
    int len_tex1 = _len_char(tex1);

    for (i=0;i<len_tex1;i++)
    {
        tex2[i]=tex1[i];
    }
}