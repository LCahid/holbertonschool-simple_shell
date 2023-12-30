#include "main.h"
/**
  * _strtok - my strtok implementation
  * @str: string for tokenization
  * @delim: delimiter
  * Return: array of tokens
  */
char **_strtok(char *str, char delim)
{
	char **array, *start, *end;
	int i = 0, j = 1, f = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != delim)
		{
			start = str + i;
			while (str[i] != delim && str[i])
				i++;
			if (j == 1)
				array = malloc(sizeof(char *) * j), f++;
			else
				array = realloc(array, sizeof(char *) * j);
			if (str[i] == '\0')
			{
				array[j - 1] = strdup(start);
				j++;
				break;
			}
			else
			{
				end = str + i;
				*end = '\0';
				array[j - 1] = strdup(start), *end = delim, start = end;
			}
			j++;
		}
		i++;
	}
	if (f == 0)
		array = malloc(sizeof(char *));
	else
		array = realloc(array, sizeof(char *) * j);
	array[j - 1] = NULL;
	return (array);
}
