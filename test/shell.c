#include "main.h"
/**
  * main - shell start function
  * @argv: argument variables
  * @argc: argument count
  * @env: env variables
  * Return: always 0
  */
int main(int argc, char **argv, char **env)
{
	char **fcommand, *buf;
	pid_t pid;
	int status, lk = 0;

	(void)argc, path_var = get_path(env);
	while (1)
	{
		status = isatty(STDIN_FILENO), print_prompt(status);
		fcommand = get_command(&buf);
		if (fcommand == NULL)
		{
			free(buf);
			if (status)
				printf("\n");
			break;
		}
		if (!strcmp("env", fcommand[0]))
		{
			print_env(), free(buf), free(fcommand);
			continue;
		}
		fcommand[0] = find_file(fcommand[0], &lk);
		if (!fcommand[0])
		{
			perror(argv[0]), free(buf), free(fcommand), errno = 0;
			continue;
		}
		pid = fork();
		if (pid == 0)
			execve(fcommand[0], fcommand, environ);
		else
			wait(NULL);
		free(buf);
		if (lk)
			free(fcommand[0]), lk = 0;
		free(fcommand);
	}
	free_path();
	return (0);
}
