#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;

	fd = open("./test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
}
