#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **environ;

char *prompt(void);
char **split_command(char *command);
int command_exec(char **args, char *prg_name,
int cmd_count, char **path_array);
void free_array(char **array);
char *search_command(char *command, char **directories);
char **split_path(void);
char **replac_arg0(char **args, char *full_path);
void ptr_env(char **env);
void change_dir(char **args);
int is_void(char *command);
#endif
