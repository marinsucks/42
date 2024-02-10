/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:16:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/10 12:04:06 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//default background color
# define DEFAULT_COLOR 0xf1efdf
//Bytes Per Sprite
# define BPS 32

//total number of sprites
# define SPRITES_NB	5 //17

/*********** SPRITES ***********/
//top player anim #0
# define TP0 0
//right player anim #0
# define RP0 1
//bottom player anim #0
# define BP0 2
//left player anim #0
# define LP0 3
//top player anim #1
# define TP1 4
//right player anim #1
# define RP1 5
//bottom player anim #1
# define BP1 6
//left player anim #1
# define LP1 7
//top border
# define TB 8
//right border
# define RB 9
//bottom border
# define BB 10
//left border
# define LB 11
//top right corner
# define TRC 12
//bottom right corner
# define BRC 13
//bottom left corner
# define BLC 14
//top left corner
# define TLC 15
# define COIN 16

/*********** COMMANDS ***********/
# define UP_kbd data->controls[0]
# define RIGHT_kbd data->controls[1]
# define DOWN_kbd data->controls[2]
# define LEFT_kbd data->controls[3]

/*********** ERROR MESSAGES ***********/
# define ERR_MALLOC "Error\nMalloc failed\n"
# define MISSING "\033[0;31mError: map is missing, not .ber or empty.\033[0m\n"
# define TOO_SMALL "\033[0;31mError: map is too small.\033[0m\n"
# define NOT_RECT "\033[0;31mError: map is not a rectangle.\033[0m\n"
# define BAD_ELEMENTS "\033[0;31mError: map has either invalid, too many or too few \
elements.\033[0m\n"
# define INVALID_PATH "\033[0;31mError: map has no valid path or has holes.\033[0m\n"



#endif
