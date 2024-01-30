# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:17:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/30 17:03:36 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

MAIN = 	main.c
BONUS = checkerfiles/checker.c \
		checkerfiles/checker_utils.c 

SRC = 	algos.c \
		cost.c\
		optirotate.c \
		status.c \
		target.c

CMDS =	ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_rrotate.c
COBJ =	$(CMDS:.c=.o)


RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
BOLD =\033[1;37m
NC =\033[0m

all: archives
	@$(CC) $(CFLAGS) -g -o $(NAME) $(MAIN) $(SRC) archives/*.a
	@printf "$(GREEN)push_swap ready.\n$(NC)"

bonus: archives
	@$(CC) $(CFLAGS) -g -o checker $(BONUS) $(SRC) archives/*.a
	@printf "$(GREEN)checker ready.\n$(NC)"

clean:
	@rm -rf *.out* */*.out checker *.o $(OBJ)
	@echo "$(LRED)Cleaning objects & executables...$(NC)"

fclean: clean
	@rm -rf $(NAME) archives
	@make -C ./libft fclean
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: clean all

archives: libft cmds
	@mkdir -p archives
	@mv libft/libft.a cmds.a archives/

libft:
	@make -C ./libft all

cmds:
	@$(CC) $(CFLAGS) -c cmds/*.c
	@ar rcs cmds.a $(COBJ)
	@ranlib cmds.a
	@rm -rf $(COBJ)
	@printf "$(LGREEN)cmds.a ready.\n$(NC)"

.PHONY : all clean fclean re libft cmds




n = 3
file = $(n).txt
rand:
	@touch tests/$(file)
	@$(CC) $(CFLAGS) -o tests/a.out tests/generate.randargs.c
	@./tests/a.out tests/$(file) $(n)
	@rm -f tests/a.out
	@tests/edit.sh $(n)
	@echo "Please run $(BOLD)source ~/.zshrc.$(NC)"
