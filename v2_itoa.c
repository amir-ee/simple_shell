#include "main.h"

char *_int_to_arr_(int num) /*malloc*/
{
    int nm = num;
    int nm2 = num;
    int i = 0;
    int p = 0;
    char *ptr;
    int one;
    int cp_i;

    while (nm != 0)
    {
        nm /= 10;
        i++;
    }

    ptr = (char *)malloc(sizeof(char) * i + 1);

    one = 0;
    cp_i = i;

    while (p < i)
    {
        cp_i--;
        one += (nm2 % 10);
        *(ptr + cp_i) = (one + '0');
        nm2 /= 10;
        one = 0;
        p++;
    }

    *(ptr + p) = '\0';
    return (ptr); /*free*/
}
