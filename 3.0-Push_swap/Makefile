# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:17:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/24 15:12:12 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

MAIN = 	main.c
BONUS = checkerfiles/checker.c \
		checkerfiles/checker_utils.c \

SRC = 	ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_rrotate.c \
		algos.c \
		cost.c\
		optirotate.c \
		status.c \
		target.c\
		$(wildcard ./tests/test.*.c)

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
BOLD =\033[1;37m
NC =\033[0m

all: #libft
	@$(CC) $(CFLAGS) -g -o $(NAME) $(MAIN) $(SRC) libft/libft.a

clean:
#	@echo "$(RED)Cleaning Push_swap...$(NC)"
	@rm -rf *.out* */*.out checker .vscode $(OBJ)

fclean: clean
	@rm $(NAME)
	@make -C ./libft fclean

re: clean all #fclean all

libft:
	@echo "$(BOLD)Compiling libft..$(NC)"
	@make -C ./libft all

checker: clean #libft
#	@$(CC) -g -o checker $(BONUS) $(SRC) libft/libft.a
	@$(CC) $(CFLAGS) -g -o checker $(BONUS) $(SRC) libft/libft.a

.PHONY : all clean fclean re libft


f: #libft
	@$(CC) -g -o $(NAME) $(MAIN) $(SRC) libft/libft.a
	@echo "$(GREEN)Compilation nf OK :)$(NC)"

ref: clean f #fclean f


n = 3
file = $(n).txt
rand:
	@touch tests/$(file)
	@$(CC) $(CFLAGS) -o tests/a.out tests/generate.randargs.c
	@./tests/a.out tests/$(file) $(n)
	@rm -f tests/a.out
	@tests/edit.sh $(n)
	@echo "Please run $(BOLD)source ~/.zshrc.$(NC)"
