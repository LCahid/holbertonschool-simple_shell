#include "main.h"
/**
  * exec_c - execute user input
  * @fcommand: user input
  */
void exec_c(char **fcommand)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(fcommand[0], fcommand, environ);
	else
		wait(NULL);
}
