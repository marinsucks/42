# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:26:01 by mbecker           #+#    #+#              #
#    Updated: 2024/02/16 12:52:24 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c \

all: $(NAME)

$(NAME): libft
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

clean:
	@echo "$(LRED)Cleaning objects & executables...$(NC)"
	@rm -rf *.out* */*.out *.dSYM* $(OBJ)

fclean: clean
	@rm -rf $(NAME) libft/libft.a
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

libft:
	@if [ ! -f libft/libft.a ]; then make -C ./libft all; fi

.PHONY : all clean fclean re libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m