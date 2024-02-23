#include <stdio.h>
#include "pipex.h"

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 3)
	{
		printf("\033[1;31m***TRANS***\033[0;31m a value converter\033[0m\n");
		printf("Usage: trans [option] [value]\n\n");
		printf("OPTIONS:\t-c convert from char\n");

	}
	else if (argc == 2)
	{
		printf("\033[1mint: \033[1;31m%i\033[0m\n", atoi(argv[1]));
		if (ft_isprint(atoi(argv[1])))
			printf("char = %c\n", atoi(argv[1]));
		else
			printf("char = [non printable]\n");
		printf("hex = %x\n", atoi(argv[1]));
		ft_printf("bin = %b\n", atoi(argv[1]));
	}
	else if (argc == 3)
	{
		printf("\033[1mchar: \033[1;31m%c\033[0m\n", argv[2][0]);
		printf("dec = %d\n", argv[2][0]);
		printf("hex = %x\n", argv[2][0]);
		ft_printf("bin = %b\n", argv[2][0]);
	}
}