# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/21 15:45:58 by mbecker          ###   ########.fr        #
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
SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c  
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