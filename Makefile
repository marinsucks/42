RED		=\033[0;31m
GREEN	=\033[1;32m
LGREEN	=\033[0;32m
YELLOW	=\033[1;33m
LYELLOW	=\033[1;33m
GREY	=\033[1;37m
NC		=\033[0m
SWAG	=🫠

git:
	@echo "$(LGREEN)Cleaning repo...$(NC)"
	make -C ./libft fclean
	@echo "\n$(LGREEN)Adding all files to staging area...$(NC)"
	git add .
	@echo "\n$(LGREEN)Commit message = \""$m\""$(NC)"
	git commit -m "$m"
	@echo "\n$(LGREEN)Pushing origin...$(NC)"
	git push origin
	@echo "\n$(LGREEN)Pushing 42...$(NC)"
	git push 42
	@echo "\n$(GREEN)REPO PUSH COMPLETED 🫠$(NC)"
