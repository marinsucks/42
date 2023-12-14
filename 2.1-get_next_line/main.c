#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	
	//for (int i = 0; i < 5; i++)
	//{
	//	char *line = get_next_line(fd);
	//	printf("line%d: %s\n", i, line);
	//}


	char *temp = "ok ca marche ";
	char *stash = malloc(50);
	stash = "12345";
	stash = makestash(temp, stash);

	//boucle qui imprime char par char le contenu de temp. si c'est un \0, on ecrit "NULL"
	int i = 0; 
	while (stash[i])
	{
		printf("%c", stash[i]);
		if (stash[i + 1] == '\0')
			printf("NULL");
		else if (stash[i + 1] == '\n')
			printf("\\n");
		i++;
	}

}
