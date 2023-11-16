# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/16 12:24:50 by mbecker          ###   ########.fr        #
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
LGREEN	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[1;33m
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
	@printf "$(YELLOW)Generating libft object... %-38.38s \r$(NC)" $@
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

norm:
	@ls *.c *.h | grep -v -e "main.c" -e "oldmain.c" | xargs norminette
	
git:
	@echo "$(LGREEN)Cleaning repo...$(NC)"
	make fclean
	@echo "\n$(LGREEN)Adding all files to staging area...$(NC)"
	git add .
	@echo "\n$(LGREEN)Commit message = \""$m\""$(NC)"
	git commit -m "$m"
	@echo "\n$(LGREEN)Pushing origin...$(NC)"
	git push origin
	@echo "\n$(LGREEN)Pushing 42...$(NC)"
	git push 42