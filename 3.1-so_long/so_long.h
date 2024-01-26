/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/26 14:56:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# ifdef __unix__
# include "minilibx-linux/mlx.h"
# endif
# ifdef __APPLE__
# include "minilibx_opengl/mlx.h"
# endif

#endif
