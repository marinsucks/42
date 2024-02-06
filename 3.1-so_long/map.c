///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   map.c                                              :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2024/02/05 14:40:34 by mbecker           #+#    #+#             */
///*   Updated: 2024/02/06 17:03:49 by mbecker          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "so_long.h"

//int		iscorner(char **map)
//{
//	int	rows;

//	rows = ft_strlen((char *)map);
//	ft_printf("test %d\n", rows);
//	return (0);
//}

//void	draw_map(t_mlx *data, int fd)
//{
//	int		i;
//	//int		j;
//	char	*map[WHEIGHT / 8];

//	i = 0;
//	map[0] = get_next_line(fd);
//	while (map[i++])
//		map[i] = get_next_line(fd);

//	iscorner(map);

//	ft_freetab(map, FALSE);
//}



///**
// * Retrieves a map from a file with the given name.
// * 
// * @param mapname The name of the map file.
// * @return A 2D array representing the map, or NULL if the map is invalid.
// */
//char **getmap(char *mapname)
//{
//	int	i;
//	int	fd;
//	char **map;

//	i = ft_strlen(mapname);
//	if (i < 5 || mapname[i - 4] != '.' || mapname[i - 3] != 'b' 
//		|| mapname[i - 2] != 'e' || mapname[i - 1] != 'r')
//		return (NULL);
//	fd = open(mapname, O_RDONLY);
//	if (fd < 0)
//		return (NULL);
//	i = 0;
//	map[0] = get_next_line(fd);
//	while (map[i++])
//		map[i] = get_next_line(fd);
//	if (!is_valid_map(map))
//		return(ft_freetab(map, TRUE), NULL);
//	return (map);
//}

//int main(void)
//{
	//char 	**test;
	//char *argv[] = {
	//	"tests/ok2.ber",
	//	"tests/ok.ber",
	//	"tests/badbtmwall.ber",
	//	"tests/badlftwall.ber",
	//	"tests/badrgtwall.ber",
	//	"tests/badtopwall.ber",
	//	"tests/empty.ber",
	//	"tests/invalidchar.ber",
	//	"tests/maptest.sh",
	//	"tests/noC.ber",
	//	"tests/noE.ber",
	//	"tests/noP.ber",
	//	"tests/noPEC.ber",
	//	"tests/notrect.ber",
	//	"tests/onewall.ber",
	//	"tests/twowalls.ber",
	//	NULL
	//};
	//for (int i = 0; i < 16; i++)
	//{
	//	test = getmap(argv[i]); 
	//	ft_printf("%s\n%p\n\n", argv[i], map);
	//}
//}