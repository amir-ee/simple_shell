#include "main.h"

int z_arr_to_int(char *arr)
{
    int len_arr;
    int i;
    int ruslet = 0;
    int to_int;

    len_arr = _len_char(arr);

    for (i = 0; i < len_arr; i++)
    {
        to_int = 0;
        if (arr[i] >= 48 && arr[i] <= 57)
        {
            to_int = arr[i] - 48;

            ruslet += to_int;

            if (i != (len_arr - 1))
            {
                ruslet *= 10;
            }
        }
        else
        {
            return (-1);
        }
    }
    return (ruslet);
}