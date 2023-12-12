#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);


	char res[BUFFER_SIZE];
	int ret = read(fd, res, BUFFER_SIZE);
	if (ret == -1)
		return 1;

	char *buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return 1;
	printf("ret = %d\nres = %s\nfd = %d\n", ret, res, fd);

	free(buffer);
	return 0;
}
