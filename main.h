#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/* defindeing */
#define END_OF_FILE -1
#define ENV_variables environ
#define PATH "PATH"

/* structsss */
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    char *path;
    int length;
} AssembledPath;

/* newwwww */
char *display_AND_get_line(void);
void new_line_and_status(char *text);
char *get_valid_path(char *command);
void free_2d_1(char **im_2d_arr);
void zz_p_eror_zz(char *name_program, int count_loop, char *command, char *messej);

/* string-func */
int _len_char(char *tx);
char *str_copy(char *tx);
char **_split_str(char *text);
char *str_copy_const(const char *tx);
char *_assemble(char *path, char *command);
int _cmp(char *x1, char *x2);
char *_int_to_arr_(int num);
int stringLength_const_arr(const char *str);
int z_arr_to_int(char *arr);

/* beltin func */
int cheacking_if_beild_in_func(char **args, int *hold_on, char *argv, int indx, char **pnt2, char ***env_adrrses, int *env_counter, char **pwd2, int *cd_cn2, char ***dirctures_two2, char **path_f_time2, int *c_cd_adv2, int *cn_null2, char **home_path2);
void _simpel_exit(int *hold_on, char **args, char *argv, int indx, char ***env_adrrses);
void _display_env_var();

/* noooooooooot */

int my_z_executing_func(char **command, char *argv, int idx);
char *my_z_get_env_z(char *variable);

/* v6 */
ssize_t _my_z_get_line(char **lineptr, size_t *n, int fd);
void _copy_this_inside_this_and_my_z(char *tex1, char *tex2);

/* v-advanced */
char *my_z_strtok(char *str, const char *delim);
void zz_p_eror_exit_zz(char *name_program, int count_loop, char **command, char *messej);
int z_check_num(char *args);
int z_setenv(const char *name, const char *value, char **pnt3);
void z_p_erore_env();
int zz_cd(char **args, char **pwd3, int *cd_cn3, char ***dirctures_two3, char **path_f_time3, int *c_cd_adv3, int *cn_null3, char **home_path3, char *argv, int indx);
void zz_p_eror_cd_zz(char *name_program, int count_loop, char **command, char *messej);

/* str_func advanced */
void z_sprintf(char *ruslet, const char *str, const char *f_str, const char *s_str);
int z_strncmp(char *f_str, const char *s_str, int len_mx);

/* advanced_tasks */
int my_z_separator(char *text, char *argv, int *hold_on);
int z_check_others(char *text, char *argv, int *hold_on, char **text_nw);


#endif
