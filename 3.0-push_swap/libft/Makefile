# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/25 16:13:15 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a

SRC		=	error.c ft_atoi.c ft_base.c ft_bzero.c ft_calloc.c ft_free.c \
			ft_is.c ft_itoa.c ft_len.c ft_lst1.c ft_lst2.c ft_mem.c ft_printf.c \
			ft_printf2.c ft_put.c ft_revert.c ft_split.c ft_strcat.c ft_strchr.c \
			ft_strcmp.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c\
			ft_strstr.c ft_strtrim.c ft_substr.c ft_to.c ft_wordcount.c get_next_line.c
OBJ		= 	$(SRC:.c=.o)

HEADER	= libft.h
NAME	= libft.a

RED		=\033[1;31m
LRED	=\033[0;31m
GREEN	=\033[1;32m
LGREEN	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[0;33m
GREY	=\033[1;37m
NC		=\033[0m

.PHONY	: all clean fclean re

all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -rf $(OBJ)
	@echo "$(LGREEN)libft.a ready.$(NC)"

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)

# PAS DE WILDCARD AUTORISEE :(
#%.o: %.c $(HEADER)
#	@printf "$(YELLOW)Generating libft object: %-38.38s \r$(NC)" $@
#	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@echo "$(LRED)Cleaning libft...$(NC)"
	@rm -rf a.out libexe a.out.dSYM .vscode obj/ $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all