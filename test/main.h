#ifndef MAINH
#define MAINH
#define PATH "PATH"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
char **get_command(char **);
char **get_path(char **);
void print_env(void);

#endif
