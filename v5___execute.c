#include "main.h"

int my_z_executing_func(char **command, char *argv, int idx)
{
    char *full_cmd;
    pid_t child;
    int status;
    char *messej = "not found";

    full_cmd = get_valid_path(command[0]);

    if (full_cmd == NULL)
    {
        zz_p_eror_zz(argv, idx, command[0], messej);
        free_2d_1(command);
        return (127);
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmd, command, environ) == -1)
        {
            perror("execve");

            free(full_cmd);
            full_cmd = NULL;
            free_2d_1(command);
            exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free_2d_1(command);
        free(full_cmd);
        full_cmd = NULL;
    }
    return (WEXITSTATUS(status));
}
