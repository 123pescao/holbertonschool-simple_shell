#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS

extern char **environ;

void execute(char *args[]);
void dprompt(void);
void int_mode(void);
void non_int_mode(FILE *stream);
void parse_command(char *command, char *args[]);

#endif
