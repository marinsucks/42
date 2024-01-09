# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:17:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/09 12:31:59 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m

all: libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a
	@echo "$(GREEN)Compilation OK :)$(NC)"

f: #libft
	@$(CC) -o $(NAME) $(SRC) libft/libft.a
	@echo "$(GREEN)Compilation nf OK :)$(NC)"

clean:
	@echo "$(RED)Cleaning $$(pwd)...$(NC)"
	@rm -rf *.out* */*.out  .vscode $(OBJ)

fclean: clean
	@rm -f $(NAME)
#	@make -C ./libft fclean

ref: fclean f

re: fclean all

libft:
	@echo "$(GREY)Compiling libft..$(NC)"
	@make -C ./libft all

.PHONY : all clean fclean re libft
