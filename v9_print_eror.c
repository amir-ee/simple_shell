#include "main.h"

void z_p_erore_env()
{
    char *msj = "setenv: Too many arguments.";
    int len_msj = _len_char(msj);
    
    write(2, msj, len_msj);
    write(2,"\n",1);
}