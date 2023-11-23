# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 14:41:36 by mbecker           #+#    #+#              #
#    Updated: 2023/11/23 14:16:02 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

SRC_FILES	=	$(patsubst %.c,%,$(wildcard *.c))
SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))
OBJDIR		=	obj/

LIBFT = ./libft/libft.a
LIBFT_SRC = $(wildcard ./libft/*.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

RED		=\033[1;31m
LRED	=\033[0;31m
GREEN	=\033[1;32m
LGREEN 	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[0;33m
GREY	=\033[1;30m
NC		=\033[0m

all: $(NAME)

$(NAME): libft $(OBJ) 
	@ar rcs $(NAME) $(OBJDIR)*.o
	@ranlib $(NAME)

$(OBJ):
	@$(CC) $(CFLAGS) -c *.c
	@mv $(OBJ) $(OBJDIR)

libft:
	@make -C ./libft all
	@cp libft/libft.a $(NAME)
	@if [ ! -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi
	@mv libft/*.o obj/

clean:
	@echo "$(RED)Removing exe & obj...$(NC)"
	@rm -rf *.out* testexe .vscode $(OBJ) $(OBJDIR) libft/*.o libft/*.gch

fclean: clean
	@rm -f $(NAME) libft/libft.a

re: fclean all


test: libft
	@$(CC) $(CFLAGS) -g obj/*.o -o testexe $(SRC)
	@echo "$(GREEN)Compilation OK\n\n$(NC)"
	@./testexe

ftest: libft
	@$(CC) -g obj/*.o -o testexe $(SRC)
	@echo "$(GREEN)Compilation OK\n\n$(NC)"
	@./testexe

git:
	@echo "$(LGREEN)Cleaning repo...$(NC)"
	make fclean
	@echo "\n$(LGREEN)Adding all files to staging area...$(NC)"
	git add .
	@echo "\n$(LGREEN)Commit message = \"m\"$(NC)"
	git commit -m "m"
	@echo "\n$(LGREEN)Pushing printf...$(NC)"
	git push printf
	@echo "\n$(GREEN)REPO PUSH COMPLETED 🫠$(NC)"

.PHONY : all clean fclean re libft