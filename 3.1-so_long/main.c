/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/26 17:15:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(void)
{
    void	*connection;
    void	*window;

    connection = mlx_init();
	if (!connection)
		return (1);
	window = mlx_new_window(connection, 640, 480, "Hello world!");
	if (!window)
		return (1); //and free the rest
	mlx_loop(connection);
    mlx_destroy_display(connection);
    free(connection);
}
