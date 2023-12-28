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
	char **fcommand, *buf;
	pid_t pid;
	struct stat st;
	int status;

	(void)argc;
	while (1)
	{
		status = isatty(STDIN_FILENO);
		if (status)
			printf("#cisfun$ ");
		else
			errno = 0;
		fcommand = get_command(&buf);
		if (fcommand == NULL)
		{
			free(buf);
			if (status)
				printf("\n");
			break;
		}
		if (stat(fcommand[0], &st) == -1)
		{
			perror(argv[0]);
			free(buf);
			free(fcommand);
			continue;
		}
		pid = fork();
		if (pid == 0)
			execve(fcommand[0], fcommand, environ);
		else
			wait(NULL);
		free(buf);
		free(fcommand);
	}
	return (0);
}
