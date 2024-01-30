# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:43:04 by mbecker           #+#    #+#              #
#    Updated: 2024/01/30 13:52:10 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
else ifeq ($(shell uname), Darwin)
MLX = -Lminilibx-linux -lmlx_Darwin -L/opt/X11/lib -lX11 -lXext
endif

NAME = so_long

#SRC = main.c
SRC = 4_pixel_put_slow.c

all: archives
	@$(CC) $(CFLAGS) -g $(SRC) archives/*.a $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

clean:
	@rm -rf *.out* */*.out *.dSYM* *.o $(OBJ)
	@echo "$(LRED)Cleaning objects & executables...$(NC)"

fclean: clean
	@rm -rf $(NAME) archives
	@make -C ./libft fclean
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: clean all

archives: libft
	@mkdir -p archives
	@mv libft/libft.a archives/
	@cp minilibx*/*.a archives/

libft:
	@make -C ./libft all

fetchlibft:
	@cp -r ../.utils/libft ./

.PHONY : all clean fclean re archives libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m