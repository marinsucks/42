/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:16:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/14 11:48:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

// default background color
# define DEFAULT_COLOR 0xf1efdf

/*********** SPRITES ***********/
// Bytes Per Sprite
# define BPS 32

# define SPRITES_NB 17

# define WALL 0
# define FLOOR 1
# define EXIT1 2
# define EXIT2 3
# define COIN 4

// player facing down
# define PDOWN 5
# define PDOWN1 6
# define PDOWN2 7

// player facing right
# define PRIGHT 8
# define PRIGHT1 9
# define PRIGHT2 10

// player facing up
# define PUP 11
# define PUP1 12
# define PUP2 13

// player facing left
# define PLEFT 14
# define PLEFT1 15
# define PLEFT2 16

/*********** PATHS ***********/
# define WALL_P "sprites/wall.xpm"
# define FLOOR_P "sprites/floor.xpm"
# define EXIT1_P "sprites/exit_open.xpm"
# define EXIT2_P "sprites/exit_closed.xpm"
# define COIN_P "sprites/pokeball.xpm"
# define PD_P "sprites/player/Ethan_d0.xpm"
# define PD1_P "sprites/player/Ethan_d1.xpm"
# define PD2_P "sprites/player/Ethan_d2.xpm"
# define PR_P "sprites/player/Ethan_r0.xpm"
# define PR1_P "sprites/player/Ethan_r1.xpm"
# define PR2_P "sprites/player/Ethan_r2.xpm"
# define PU_P "sprites/player/Ethan_u0.xpm"
# define PU1_P "sprites/player/Ethan_u1.xpm"
# define PU2_P "sprites/player/Ethan_u2.xpm"
# define PL_P "sprites/player/Ethan_l0.xpm"
# define PL1_P "sprites/player/Ethan_l1.xpm"
# define PL2_P "sprites/player/Ethan_l2.xpm"

/*********** ERROR MESSAGES ***********/
# define ERR_MALLOC "Error\nMalloc failed\n"
# define MISSING "Error\n\033[0;31mMap is missing, not .ber or empty.\033[0m\n"
# define TOO_SMALL "Error\n\033[0;31mMap is too small.\033[0m\n"
# define NOT_RECT "Error\n\033[0;31mMap is not a rectangle.\033[0m\n"	
# define BAD_PATH "Error\n\033[0;31mMap has holes or no valid path.\033[0m\n"

#endif
