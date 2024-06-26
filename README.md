# Simple Shell

# Table of contents

- Description #Description#
- Functions #Functions#
- Requirements #Requirements#
- Example #Example#
- Compilation #Compilation#
- Collaborators #Collaborators#

## Description

    This would be a simple UNIX command line interpreter shell using C. A command line interpreter, allowing user to input
commands and executing them on the underlying operating system.

## Functions
- It displays a shell prompt ('($)') and waits for user input.
- Executes commands.
- Handles interactive mode & non-interactive mode.
- Supports Ctrl+D.
-Does not support advanced features.

## Requirements

List of allowed functions and system calls+

    all functions from string.h
    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    printf (man 3 printf)
    fprintf (man 3 fprintf)
    vfprintf (man 3 vfprintf)
    sprintf (man 3 sprintf)
    putchar (man 3 putchar)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## Examples of usage:

To start the shell in interactive mode:
.B
$ hsh
($)
($)
(exit)

To execute a command in non-interactive mode:
.B
$ echo "/bin/ls" | hsh
hsh main.c shell.c test_ls_2

.SH EXIT STATUS
The
.B hsh
shell returns the following exit statuses:

0 - Successful execution.
1 - Command not found or error occurred.
2 - Invalid usage.

## Compilation 
- This is the way to compile the shell program.
- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
### Collaborators

- Jose Caban
- Carlos Soto
- 2024
