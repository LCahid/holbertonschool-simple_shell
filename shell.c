#include "main.h"
#include <errno.h>
/**
  * main - shell start function
  * @argv: argument variables
  * @argc: argument counter
  * Return: always 0
  */
int main(int argc, char **argv)
{
	char **fcommand;
	size_t n = 0;
	pid_t pid;
	struct stat st;
	int status;

	while (1)
	{
		status = isatty(STDIN_FILENO);
		if (status)
			printf("#cisfun$ ");
		else
			errno = 0;
		fcommand = get_command();
		if (fcommand == NULL)
		{
			break;
		}
		if (stat(fcommand[0], &st) == -1)
		{
			perror(argv[0]);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execve(fcommand[0], fcommand, environ);
		}
		else
			wait(NULL);
	}
	return (0);
}
