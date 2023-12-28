#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define S 8

void _getline(char **buf, int stream)
{
	int c = read(stream, *buf, 1);
	int off = 0;

	while ((*buf)[c - 1] != '\n' && (*buf)[c - 1] != 4)
	{
		if (c > S + off)
		{
			*buf = realloc(*buf, S + c);
			if (!(*buf))
			{
				free(*buf);
				exit(1);
			}
			off += S;
		}
		read(stream, *buf + c, 1);
		c++;
	}
	*buf = realloc(*buf, c);
	if (!(*buf))
	{
		free(*buf);
		exit(1);
	}
}

int main()
{
	char *buf = malloc(S);

	_getline(&buf, 0);
	printf("%s", buf);
	free(buf);
	return (0);
}
