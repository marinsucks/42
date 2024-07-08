# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 12:17:46 by mbecker           #+#    #+#              #
#    Updated: 2024/07/08 12:58:44 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BraiiiiiiinnnzzzZ

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

.PHONY : all clean fclean re libft

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) compiled.$(NC)"

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

libft:
	@if [ ! -f libft/libft.a ]; then make -C ./libft all; fi


RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m