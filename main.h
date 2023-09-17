#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

extern char **environ;
/*******FUNCTIONS*******/
char *prompt(void);
char **split_command(char *command);
int command_exec(char **argv, char **path_array);
char *search_command_path(char *command, char **directories_array);
int dierctory_count(char *path);
char **split_path(void);
char **replace_argv0(char **argv, char *full_path);
void string_array_free(char **array);
void shell_exit(char **argv);
void ptrenv(void);
int is_num(char *argv);
int ptr_str(char *str);
#endif
