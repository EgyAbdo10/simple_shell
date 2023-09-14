#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>
extern char **environ;
int my_strlen(char *str);
char *my_strdup(char *str);
char *clear_spaces(char *str);
void free_double_ptr(char **argvec);
char *my_strchr(char *str, char chr);
int my_strncmp(char *str1, char *str2, int n_chr);
char **split_args(char *line);
char *my_get_env(char *var, char **env);
char **split_path(char *path);
char *my_strcat(char *str1, char *str2);
char *search_command(char *command, char **dirs_arr);
char *concat_all(int argc, ...);
int power(int num, int exp);
int str_to_int(char *str);
int num_len(int num);
char *int_to_str(int number);
void print_error(char *exec_file, char *command, int prompet_num);
int execute_command(char *clr_line, char *exe, char **env, int n, int *is_ex);
void print_env(char **argvec, int *ex_st);
char *handle_comment(char *line);
#endif
