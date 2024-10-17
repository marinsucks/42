# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 15:07:35 by mbecker           #+#    #+#              #
#    Updated: 2024/10/17 13:19:15 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC =	Bureaucrat.cpp \
			AForm.cpp \
			main.cpp \

OBJ_DIR = obj
OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(LYELLOW)Objects successfully compiled in $(YELLOW)$$PWD/obj/$(LYELLOW).$(NC)"
	@$(CC) $(CFLAG) $(SRC) -o $(NAME)
	@if [ -f $(NAME) ] ; then echo "$(LGREEN)Created $(GREEN)$(NAME)$(LGREEN).$(NC)" ; \
	else echo "Failed to compile $(RED)$(NAME)$(LRED).$(NC)"; fi

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p  $(OBJ_DIR)
	@echo "$(LYELLOW)Compiling $(YELLOW)$<$(NC)"
	@$(CC) $(CFLAG) -c $< -o $@
	@printf "\033[1A\033[2K\r"

clean:
	@echo "$(LRED)Removing $(RED)objects$(LRED)...$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(LRED)Removing $(RED)$(NAME)$(LRED)...$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m