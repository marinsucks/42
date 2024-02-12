/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:16:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/12 11:31:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//default background color
# define DEFAULT_COLOR 0xf1efdf


/*********** SPRITES ***********/
//Bytes Per Sprite
# define BPS 32

# define SPRITES_NB	16

# define WALL img[0].ptr
# define FLOOR img[1].ptr
# define EXIT img[2].ptr
# define COIN img[3].ptr

//player facing down
# define PDOWN img[4].ptr
# define PDOWN1 img[5].ptr
# define PDOWN2 img[6].ptr

//player facing right
# define PRIGHT img[7].ptr
# define PRIGHT1 img[8].ptr
# define PRIGHT2 img[9].ptr

//player facing up
# define PUP img[10].ptr
# define PUP1 img[11].ptr
# define PUP2 img[12].ptr

//player facing left
# define PLEFT img[13].ptr
# define PLEFT1 img[14].ptr
# define PLEFT2 img[15].ptr

/*********** PATHS ***********/
# define WALL_PATH "sprites/wall.xpm"
# define FLOOR_PATH "sprites/floor.xpm"
# define EXIT_PATH "sprites/exit.xpm"
# define COIN_PATH "sprites/pokeball.xpm"
# define PD_PATH "sprites/player/Ethan_d0.xpm"
# define PD1_PATH "sprites/player/Ethan_d1.xpm"
# define PD2_PATH "sprites/player/Ethan_d2.xpm"
# define PR_PATH "sprites/player/Ethan_r0.xpm"
# define PR1_PATH "sprites/player/Ethan_r1.xpm"
# define PR2_PATH "sprites/player/Ethan_r2.xpm"
# define PU_PATH "sprites/player/Ethan_u0.xpm"
# define PU1_PATH "sprites/player/Ethan_u1.xpm"
# define PU2_PATH "sprites/player/Ethan_u2.xpm"
# define PL_PATH "sprites/player/Ethan_l0.xpm"
# define PL1_PATH "sprites/player/Ethan_l1.xpm"
# define PL2_PATH "sprites/player/Ethan_l2.xpm"

/*********** COMMANDS ***********/
# define UP_KBD data->command[0]
# define RIGHT_KBD data->command[1]
# define DOWN_KBD data->command[2]
# define LEFT_KBD data->command[3]

/*********** ERROR MESSAGES ***********/
# define ERR_MALLOC "Error\nMalloc failed\n"
# define MISSING "\033[0;31mError: map is missing, not .ber or empty.\033[0m\n"
# define TOO_SMALL "\033[0;31mError: map is too small.\033[0m\n"
# define NOT_RECT "\033[0;31mError: map is not a rectangle.\033[0m\n"
# define BAD_ELEMENTS "\033[0;31mError: map has either invalid, too many or too few \
elements.\033[0m\n"
# define INVALID_PATH "\033[0;31mError: map has no valid path or has holes.\033[0m\n"



#endif
