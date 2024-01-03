#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

void	print_file(int fd)
{
	char *line;
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd);
		if (line)	
			printf("line%d:\t%s\n", i, line);
		else
		{
			printf("line%d:\t%s\n", i, line);
			free(line);
			break;
		}
		free(line);
	}
}


int	main()
{
	//int fd = open("other/empty.txt", O_RDONLY);
	//int fd = open("other/test.txt", O_RDONLY);
	//print_file(fd);

	//test avec NULL pour ft_strjoin
	char *oldtemp = NULL;
	char stash[10];
	ft_strjoin(oldtemp, stash);

	//close(fd);
}
