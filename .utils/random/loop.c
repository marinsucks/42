#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	while (argc == 1)
		;
	if (atoi(argv[1]) <= 0)
	{
		printf("Usage: %s <seconds (optional for limited time)>\n", argv[0]);
		return (1);
	}
	if (argc > 1)
		sleep(atoi(argv[1]));

	return 0;
}