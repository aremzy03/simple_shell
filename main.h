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
void command_exec(char **args);
void free_array(char **array);

#endif
