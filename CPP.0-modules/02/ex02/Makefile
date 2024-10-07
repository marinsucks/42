NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) main.cpp Fixed.cpp
	@if [ -f $(NAME) ] ; then \
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) created.$(NC)" ; \
	else \
		echo "$(LRED)./$(RED)$(NAME)$(LRED) failed to compile.$(NC)" ; \
	fi

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

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