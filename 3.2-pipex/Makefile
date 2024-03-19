# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:26:01 by mbecker           #+#    #+#              #
#    Updated: 2024/03/19 15:30:38 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	main.c \
		commands.c

BONUS =	bonus/main.c \
		bonus/commands.c \
		bonus/here_doc.c


all: $(NAME)

$(NAME): libft
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

bonus: libft
	@$(CC) $(CFLAGS) $(BONUS) libft/libft.a -o $(NAME)bonus
	@echo "$(GREEN)$(NAME)bonus ready.$(NC)"

clean:
	@echo "$(LRED)Cleaning objects & executables...$(NC)"
	@rm -rf *.out* */*.out *.dSYM* $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(NAME)bonus libft/libft.a *infile *outfile pipex.tester 
	@make -C ./libft fclean
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

libft:
	@if [ ! -f libft/libft.a ]; then make -C ./libft all; fi

.PHONY : all clean fclean re libft



RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m

f: libft
	@$(CC) $(SRC) libft/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) ready.$(NC)"

tester: all
	@if [ ! -d "pipex.tester" ]; then \
		echo "$(GREEN)Cloning tester...$(LGREEN)"; \
		git clone https://github.com/vfurmane/pipex-tester pipex.tester; \
	fi
	@chmod +x pipex.tester/run.sh
	@echo "$(YELLOW)Tester ready.$(NC)"
	@echo "$(RED)Running tester...$(NC)"
	@printf "..\nn" | pipex.tester/run.sh
	