#include"main.h"

int _cmp(char *x1, char *x2)
{

    int lx1 = _len_char(x1);
    int lx2 = _len_char(x2);

    int con = 0;

    if (lx1 == lx2)
    {
        while (con <= lx1)
        {
            if (x1[con] == x2[con])
            {
                /* testing */
            }
            else
            {
                return (-1);
            }
            con++;
        }
    }
    else
    {
        return (-1);
    }

    return (0);
}
