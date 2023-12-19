#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);

	char tes[BUFFER_SIZE + 1];
	int readval = read(fd, tes, BUFFER_SIZE);
	//tes[readval] = 0;
	printf("%s\n", tes);

	//char *line;
	//for (int i = 0; line; i++)
	//{
	//	line = get_next_line(fd);
	//	if (line)	
	//		printf("line%d:\t%s\n", i, line);
	//	else
	//		printf("line%d:\t%s\n", i, "NULL");
	//	free(line);
	//}
	//close(fd);
}
