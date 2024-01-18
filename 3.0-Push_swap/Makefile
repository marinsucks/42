# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:17:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/18 10:52:46 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = 	main.c \
		ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_rrotate.c \
		ft_sorted.c \
		ft_bubblesort.c \
		$(wildcard ./test.*.c)

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
BOLD =\033[1;37m
NC =\033[0m

all: #libft
	@$(CC) $(CFLAGS) -g -o $(NAME) $(SRC) libft/libft.a
	@echo "$(GREEN)Compilation OK :)$(NC)"

f: #libft
	@$(CC) -g -o $(NAME) $(SRC) libft/libft.a
	@echo "$(GREEN)Compilation nf OK :)$(NC)"

clean:
	@echo "$(RED)Cleaning Push_swap...$(NC)"
	@rm -rf *.out* */*.out  .vscode $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

ref: clean f #fclean f

re: clean all #fclean all

libft:
	@echo "$(BOLD)Compiling libft..$(NC)"
	@make -C ./libft all

.PHONY : all clean fclean re libft


n = 3
file = $(n).txt
rand:
	@touch testfiles/$(file)
	@$(CC) $(CFLAGS) -o testfiles/a.out testfiles/generate.randargs.c
	@./testfiles/a.out testfiles/$(file) $(n)
	@rm -f testfiles/a.out
	@testfiles/edit.sh $(n)
	@echo "Please run $(BOLD)source ~/.zshrc.$(NC)"
