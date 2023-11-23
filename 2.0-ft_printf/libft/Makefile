# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/23 17:29:37 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED		=	\033[1;31m
LRED	=	\033[0;31m
GREEN	=	\033[1;32m
LGREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
LYELLOW	=	\033[0;33m
GREY	=	\033[1;37m
NC		=	\033[0m


CC 		=	cc
CFLAGS 	=	-Wall -Wextra -Werror

NAME 	=	libft.a
SRC		=	$(wildcard *.c)
OBJ		= 	$(SRC:.c=.o)


all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)Libft OK$(NC)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing exe & obj..."
	@rm -rf a.out* .vscode $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY	: all clean fclean re