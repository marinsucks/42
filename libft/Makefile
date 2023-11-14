# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/14 17:17:23 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a

SRC 	= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

HEADER	= libft.h
NAME	= libft.a

RED		=\033[0;31m
GREEN	=\033[1;32m
ORANGE	=\033[1;33m
GREY	=\033[1;37m
NC		=\033[0m

.PHONY	: all clean fclean re

all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "$(RED)\nDone!$(NC)"

clean:
	@echo "Removing exe & obj..."
	@rm -rf a.out libexe a.out.dSYM .vscode $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	@printf "$(ORANGE)Generating libft object... %-38.38s \r$(NC)" $@
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@$(CC) $(CFLAGS) -g -o libexe $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./libexe

ftest:
	@$(CC) -g -o libexe $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./libexe
	@rm -rf libexe

git:
	@echo "$(RED)Cleaning repo...$(NC)"
	@make fclean
	@echo "Adding all files to staging area..."
	@git add .
	git commit -m "$m"
	git push 42 && git push origin

norm:
	@ls *.c *.h | grep -v -e "main.c" -e "oldmain.c" | xargs norminette