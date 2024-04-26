#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

extern char **environ;

void int_mode(void);
void process_input(char *input);
void execute_command(char *args[]);
void non_int_mode(FILE *stream);
void read_input(int fd, char *buffer);
void parse_command(char *command, char *args[]);

#endif
