# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2023/11/17 17:22:00 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a

SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c
OBJ		= 	$(SRC:.c=.o)

SRC_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c  

OBJ_B	=	$(SRC_B:.c=.o)

HEADER	= libft.h
NAME	= libft.a

RED		=\033[0;31m
GREEN	=\033[1;32m
LGREEN	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[1;33m
GREY	=\033[1;37m
NC		=\033[0m
SWAG	=🫠

.PHONY	: all clean fclean re

all: 	$(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "$(RED)\nDone!$(NC)"

bonus: $(OBJ) $(OBJ_B)
	@ar rc $(NAME) $(OBJ) $(OBJ_B)
	@ranlib $(NAME)
	@echo "$(RED)\nDone!$(NC)"

clean:
	@echo "Removing exe & obj..."
	@rm -rf a.out libexe a.out.dSYM .vscode $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	@printf "$(YELLOW)Generating libft object... %-38.38s \r$(NC)" $@
	@$(CC) $(CFLAGS) -c $< -o $@

norm:
	@ls *.c *.h | grep -v -e "main.c" -e "oldmain.c" | xargs norminette

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRC_b)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJ_B)

test:
	@$(CC) $(CFLAGS) -g -o libexe $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./libexe

ftest:
	@$(CC) -g -o libexe $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./libexe
	@rm -rf libexe
	
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
	@echo "\n$(GREEN)REPO PUSH COMPLETED 🫠$(NC)"