#include "main.h"
/**
  * find_path - find path in env variables
  * @var: env variable
  * @i: row index
  * @j: column index
  */
void find_path(char **var, int *i, int *j)
{
	int len = strlen(PATH);

	while (var[*i])
	{
		while (var[*i][*j])
		{
			if (*j > len)
				break;
			if (var[*i][*j] == '=')
				return;
			if (var[*i][*j] == PATH[*j])
				(*j)++;
			else
				break;
		}
		(*i)++;
		*j = 0;
	}
	*i = 0;
	*j = 0;
}
/**
  * get_path - init path array
  * @env: environment variables array pointer
  * Return: path array
  */
char **get_path(char **env)
{
	int i = 0, j = 0, k = 0;
	char **array, *buf;

	find_path(env, &i, &j);
	if (i == 0 && j == 0)
	{
		return (NULL);
	}
	array = malloc(sizeof(char *) * 2);
	if (array == NULL)
		return (NULL);
	j++;
	buf = strtok(env[i] + j, ":");
	if (!buf)
	{
		free(array);
		return (NULL);
	}
	array[k++] = strdup(buf);
	while (1)
	{
		buf = strtok(NULL, ":");
		if (buf)
		{
			array[k] = strdup(buf);
			array = realloc(array, sizeof(char *) * (k + 2));
			if (array == NULL)
				return (NULL);
		}
		else
		{
			array[k] = NULL;
			break;
		}
		k++;
	}
	free(buf);
	return (array);
}
/**
 * free_path - free path buffer
 */
void free_path(void)
{
	int i = 0;

	if (!path_var)
		return;
	while (path_var[i])
		free(path_var[i++]);
	free(path_var);
}
