# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 15:40:22 by mbecker           #+#    #+#              #
#    Updated: 2024/06/28 16:16:45 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	main.c \
		\
		error.c \
		free.c \
		routine.c \
		threads.c \
		utils.c

all: $(NAME)

$(NAME):
	@if [ ! -f philo ]; then \
		$(CC) $(CFLAGS) $(SRC) -o $(NAME); \
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) ready.$(NC)"; \
	else \
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) already compiled.$(NC)"; \
	fi


clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

.PHONY : $(NAME) all clean fclean re

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m
