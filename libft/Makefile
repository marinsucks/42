# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/13 11:14:05 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a

SRC 	= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

HEADER	= libft.h
NAME	= libft.a

.PHONY	: all clean fclean re

all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;31m\nDone!\033[0m"

clean:
	@echo "Removing exe & obj..."
	rm -rf a.out libexe a.out.dSYM .vscode $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	@printf "\033[0;33mGenerating libft object... %-38.38s \r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@echo "Compiling all .c files..."
	@$(CC) $(CFLAGS) -g -o libexe $(SRC)
	@./libexe
# @rm -rf libexe

ftest:
	@echo "Compiling all .c files..."
	@$(CC) -g -o libexe $(SRC)
	@./libexe
	@rm -rf libexe

git:
	@echo "Cleaning house..."
	@make fclean
	@echo "Adding all files to staging area..."
	@git add .
	git commit -m "$m"
	git push 42 && git push origin

norm:
	@ls *.c *.h | grep -v -e "main.c" -e "oldmain.c" | xargs norminette



#FUNCTION_NAME = $(firstword $(MAKECMDGOALS))
#comp:
#	@echo "Compiling all .c files..."
#	@$(CC) -o libexe $(SRC)

#compflags:
#	@echo "Compiling all .c files..."
#	@$(CC) $(CFLAGS) -o libexe $(SRC)

#ft_%:
#	@echo "Compiling $@.c..."
#	@$(CC) $(CFLAGS) $@.c -o a.out
#	@./a.out

#func: compmain exe

#compmain:
#	@echo "Compiling *.c (except main)..."
#	@ls *.c | grep -v "main.c" | xargs $(CC) $(CFLAGS) -g -o libexe

#exe: 
#	@echo "Executing libft..."
#	@./libexe
