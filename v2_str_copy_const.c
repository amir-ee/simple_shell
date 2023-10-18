#include "main.h"

char *str_copy_const(const char *tx) /*malloc*/
{
    int len_x1 = stringLength_const_arr(tx);

    char *ptr = (char *)malloc(sizeof(char) * (len_x1 + 1)); /*malloc*/

    int i = 0;

    while (i < len_x1)
    {
        *(ptr + i) = tx[i];
        i++;
    }

    *(ptr + i) = '\0';

    return (ptr);
}
