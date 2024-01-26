# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:43:04 by mbecker           #+#    #+#              #
#    Updated: 2024/01/26 11:50:02 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = main.c

all: archives
	@$(CC) $(CFLAGS) -g -o $(NAME) $(MAIN) $(SRC) archives/*.a
	@echo "$(GREEN)$(NAME) ready.$(NC)"

clean:
	@rm -rf *.out* */*.out checker *.o $(OBJ)
	@echo "$(LRED)Cleaning objects & executables...$(NC)"

fclean: clean
	@rm -rf $(NAME) archives
	@make -C ./libft fclean
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: clean all

archives: libft
	@mkdir -p archives
	@mv libft/libft.a archives/

libft:
	@make -C ./libft all

.PHONY : all clean fclean re archives libft
