# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:00:14 by mbecker           #+#    #+#              #
#    Updated: 2024/01/08 17:49:12 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a

SRC		=	ft_atoi.c ft_base.c ft_bzero.c ft_calloc.c ft_is.c ft_itoa.c \
			ft_len.c ft_lst1.c ft_lst2.c ft_mem.c ft_printf2.c ft_printf.c \
			ft_put.c ft_revert.c ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c \
			ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c\
			ft_strstr.c ft_strtrim.c ft_substr.c ft_to.c ft_wordcount.c
OBJ		= 	$(SRC:.c=.o)

SRC_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c  

OBJ_B	=	$(SRC_B:.c=.o)

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
	@echo -e "$(RED)\nDone!$(NC)"

%.o: %.c $(HEADER)
	@printf "$(YELLOW)Generating libft object... %-38.38s \r$(NC)" $@
	@$(CC) $(CFLAGS) -c $< -o $@

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



so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRC_B)
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
	@echo "\n$(LGREEN)Pushing 42...$(NC)"
	git push
	@echo "\n$(GREEN)REPO PUSH COMPLETED 🫠$(NC)"

runtesters: installtesters tests

installtesters:
	@echo "$(GREEN)Installing Tripouille$(LGREEN)"
	@git clone https://github.com/Tripouille/libftTester.git Tripouille

	@echo "$(YELLOW)\nInstalling WarMachine$(LYELLOW)"
	@git clone https://github.com/0x050f/libft-war-machine.git WarMachine
	@bash WarMachine/grademe.sh
	@echo 'PATH_LIBFT="$(shell pwd)"' > tmpfile && awk 'NR==8 {print "PATH_LIBFT=\"$(shell pwd)\""} NR!=8' ./WarMachine/my_config.sh > tmpfile && mv tmpfile ./WarMachine/my_config.sh

	@echo "$(RED)\nInstalling UnitTest$(LRED)"
	@git clone https://github.com/alelievr/libft-unit-test.git UnitTest
	@echo "\$LIBFTDIR = \$(shell pwd)" > tmpfile && awk 'NR==18 {print "LIBFTDIR = \$(shell pwd)"} NR!=18' ./UnitTest/Makefile > tmpfile && mv tmpfile ./UnitTest/Makefile
	@echo "$(NC)\n"

	@pwd
	@echo "$(YELLOW)WarMachine:$(LYELLOW) Change lib path in WarMachine/my-config.sh to current dir"
	@echo "$(RED)UnitTest:$(LRED) Change lib path in UnitTest/Makefile to current dir"

tests: test2 test1 test3

test1: fclean
	@echo "$(GREEN)Executing Tripouille$(NC)"
	@make -C ./Tripouille a
	@make fclean

test2: fclean
	@echo "$(YELLOW)\nExecuting WarMachine$(NC)"
	@bash WarMachine/grademe.sh
	@make fclean

test3: fclean
	@echo "$(RED)\nExecuting UnitTest$(LRED)"
	@make -C ./UnitTest f
	@make fclean

rmtests:
	rm -rf Tripouille WarMachine UnitTest libft.so

