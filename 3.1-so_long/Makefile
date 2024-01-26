# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:43:04 by mbecker           #+#    #+#              #
#    Updated: 2024/01/26 16:34:59 by mbecker          ###   ########.fr        #
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

SRC = main.c

all: archives
	@$(CC) $(CFLAGS) -g -o $(NAME) $(SRC) archives/*.a $(MLX)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

clean:
	@rm -rf *.out* */*.out checker *.o $(OBJ)
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

.PHONY : all clean fclean re archives libft
