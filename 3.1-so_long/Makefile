# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:43:04 by mbecker           #+#    #+#              #
#    Updated: 2024/02/14 14:04:25 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

NAME =	so_long

MAIN =	main.c
SRC =	checks.c \
		display.c \
		quit.c \
		utils.c

all: archives
	@$(CC) $(CFLAGS) -g $(MAIN) $(SRC) archives/*.a $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

clean:
	@rm -rf *.out* */*.out *.dSYM* *.o $(OBJ)
	@echo "$(LRED)Cleaning objects & executables...$(NC)"

fclean: clean
	@rm -rf $(NAME) archives
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

archives: libft mlx
	@mkdir -p archives
	@if [ -f libft/libft.a ]; then mv libft/libft.a archives/; fi
	@cp minilibx*/*.a archives/

mlx:
	@if [ ! -d minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
	@if [ ! -f archives/libmlx_Linux.a ] || [ ! -d archives ]; then make -C ./minilibx-linux all; fi

libft:
	@if [ ! -f archives/libft.a ] || [ ! -d archives ]; then make -C ./libft all; fi

.PHONY : all clean fclean re archives libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m