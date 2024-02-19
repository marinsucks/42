# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2024/02/19 12:28:54 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc

ifeq ($(shell uname), Linux)
CFLAGS 	= -Wall -Wextra -Werror
else ifeq ($(shell uname), Darwin)
CFLAGS 	= -Wall -Wextra -Werror -Wno-unused-but-set-parameter
endif

NAME 	= libft.a

FREE =	free/ft_free.c
GET = 	get/get_file.c \
		get/get_next_line.c
LST =	lst/ft_lst1.c \
		lst/ft_lst2.c
MEM =	mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_mem.c
OTHER =	other/pathfinding.c
PRINT =	print/ft_printf2.c \
		print/ft_printf.c \
		print/ft_put.c \
		print/printtab.c
STR =	str/ft_atoi.c \
		str/ft_base.c \
		str/ft_is.c \
		str/ft_itoa.c \
		str/ft_len.c \
		str/ft_revert.c \
		str/ft_split.c \
		str/ft_strcat.c \
		str/ft_strchr.c \
		str/ft_strcmp.c \
		str/ft_strcpy.c \
		str/ft_strdup.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strmapi.c \
		str/ft_strset.c \
		str/ft_strstr.c \
		str/ft_strtrim.c \
		str/ft_substr.c \
		str/ft_to.c \
		str/ft_wordcount.c

SRC	=	$(FREE) $(GET) $(LST) $(MEM) $(OTHER) $(PRINT) $(STR)
OBJ	=	$(SRC:.c=.o)

HEADER	= libft.h
NAME	= libft.a

RED		=\033[1;31m
LRED	=\033[0;31m
GREEN	=\033[1;32m
LGREEN	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[0;33m
GREY	=\033[1;37m
NC		=\033[0m

.PHONY	: all clean fclean re

all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -rf $(OBJ) .obj
	@echo "$(LGREEN)libft.a ready.$(NC)"

%.o: %.c
	@mkdir -p .obj/free .obj/get .obj/lst .obj/mem .obj/print .obj/str 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(LRED)Cleaning libft...$(NC)"
	@rm -rf a.out libexe a.out.dSYM .vscode obj/ $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all