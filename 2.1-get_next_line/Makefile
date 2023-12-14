CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC)
	@echo "$(GREEN)Compilation OK :)$(NC)"

clean:
	@echo "Removing exe & obj..."
	@rm -rf *.out* */*.out *.gch .vscode $(OBJ) $(OBJ_B)

fclean: clean
	@rm -f $(NAME)

re: fclean all

libft:
	@echo "$(GREY)Compiling libft..$(NC)"
	@make -C ./libft all

ftest:
	@$(CC) -g *.c
#	@echo "$(GREEN)Compilation OK :)$(NC)"
	@./a.out

installtesters:
	@echo "$(GREEN)Installing Tripouille...$(LGREEN)"
	@git clone https://github.com/Tripouille/gnlTester.git tripouille


git:
	@echo "$(LGREEN)Cleaning repo...$(NC)"
	make fclean
	@echo "\n$(LGREEN)Adding all files to staging area...$(NC)"
	git add .
	@echo "\n$(LGREEN)Commit message = \"m\"$(NC)"
	git commit -m "m"
	@echo "\n$(LGREEN)Pushing gnl...$(NC)"
	git push gnl
	@echo "\n$(GREEN)"gnl" REPO PUSH COMPLETED 🫠$(NC)"

.PHONY : all clean fclean re