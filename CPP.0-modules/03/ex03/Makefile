# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 14:35:23 by mbecker           #+#    #+#              #
#    Updated: 2024/09/24 16:05:48 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp -o $(NAME)
	@if [ -f $(NAME) ] ; then \
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) created.$(NC)" ; \
	else \
		echo "$(LRED)./$(RED)$(NAME)$(LRED) failed to compile.$(NC)" ; \
	fi

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

.PHONY : all clean fclean re libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m