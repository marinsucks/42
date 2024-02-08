#include "../so_long.h"

int	main(void)
{
	int		fd;
	char	**map;

	char *mapnames[] = {
		//MISSING
		"empty.ber",

		//TOO SMALL
		"oneclmn.ber",
		"onecorner.ber",
		"onewall.ber",
		"twowalls.ber",

		//NOT RECTANGLE
		"notrect.ber",
		"notrect2.ber",
		"1nl.ber",
		"2nl.ber",
		"3nl.ber",
		"onlynl.ber",

		//HAS HOLES
		"badlftwall.ber",
		"badbtmwall.ber",
		"badrgtwall.ber",
		"badtopwall.ber",
		
		//ELEMENTS
		"noC.ber",
		"noE.ber",
		"noP.ber",
		"noPEC.ber",
		"invalidchar.ber",

		//PATH
		"nopath.ber",

		//OK
		"ok.ber",
		"ok2.ber",
		"ok3.ber",

		NULL
	};

	for (size_t i = 0; mapnames[i]; i++)
	{
		ft_printf("\nTEST %s\n", mapnames[i]);
		fd = open(mapnames[i], O_RDONLY);
		map = get_file(fd);
		if (!map)
		{
			ft_printf("%p$\n", map);
			is_valid_map(map);
		}
		else
		{
			print_tab(map, 0);
			ft_printf("$\n");
			is_valid_map(map);
		}
		if (map)
			ft_freetab(map, 1);
	}
}