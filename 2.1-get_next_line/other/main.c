#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);

	char *line;
	for (int i = 0; line; i++)
	{
		line = get_next_line(fd);
		if (line)	
			printf("line%d:\t%s\n", i, line);
		else
			printf("line%d:\t%s\n", i, "NULL");
		free(line);
	}
	close(fd);
}
