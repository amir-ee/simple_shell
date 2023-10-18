#include "main.h"

void zz_p_eror_exit_zz(char *name_program, int count_loop, char **command, char *messej)
{
    char *str_num = _int_to_arr_(count_loop);

    write(2, name_program, _len_char(name_program));
    write(2, ": ", 2);
    write(2, str_num, _len_char(str_num));
    write(2, ": ", 2);
    write(2, command[0], _len_char(command[0]));
    write(2, ": ", 2);
    write(2, messej, _len_char(messej));
    write(2, ": ", 2);
    write(2, command[1], _len_char(command[1]));
    write(2, "\n", 1);

    free(str_num);
}
