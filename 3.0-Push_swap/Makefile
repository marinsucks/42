# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:17:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/08 15:05:47 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(NAME) $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./$(NAME)

clean:
	@echo "Removing exe & obj..."
	@rm -rf *.out* */*.out testexe .vscode $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all

libft:
	@echo "$(GREY)Compiling libft..$(NC)"
	@make -C ./libft all

ftest:
	@$(CC) -g testexe $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./testexe

.PHONY : all clean fclean re
