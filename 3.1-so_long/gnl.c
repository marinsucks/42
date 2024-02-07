#include "so_long.h"

int	main(void)
{
	int		fd;
	char	**map = malloc(sizeof(char *) * 10);
	char 	*mapnames = "tests/onlynl.ber";

	ft_printf("TEST %s\n", mapnames + 6);
	fd = open(mapnames, O_RDONLY);
	map = get_file(fd);
	for (size_t i = 0; map[i]; i++)
		ft_printf("%s", map[i]);
}

