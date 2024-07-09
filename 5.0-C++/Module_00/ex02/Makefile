# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 14:09:50 by mbecker           #+#    #+#              #
#    Updated: 2024/07/05 17:05:10 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jobofmydreams

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = 	tests.cpp \
		Account.cpp

.PHONY : all clean fclean re libft

all: $(NAME)

$(NAME): docs
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) compiled.$(NC)"

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode *noTS.log

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

check:
	@./jobofmydreams | awk '{print $$2}' > jobofmydreams_noTS.log
	@cat 19920104_091532.log | awk '{print $$2}' > 19920104_091532_noTS.log
	diff jobofmydreams_noTS.log 19920104_091532_noTS.log
	@echo "diff exit code: $$?"

docs:
	@if [ ! -f "Account.hpp" ] || [ ! -f "tests.cpp" ] || [ ! -f "19920104_091532.log" ]; then \
		echo "$(LYELLOW)Downloading $(YELLOW)Account.hpp$(LYELLOW)\t\t from https://cdn.intra.42.fr/document/document/22780/Account.hpp...$(NC)"; \
		wget -q https://cdn.intra.42.fr/document/document/22780/Account.hpp --no-check-certificate; \
		echo "$(LYELLOW)Downloading $(YELLOW)tests.cpp$(LYELLOW)\t\t from https://cdn.intra.42.fr/document/document/22782/tests.cpp...$(NC)"; \
		wget -q https://cdn.intra.42.fr/document/document/22782/tests.cpp --no-check-certificate; \
		echo "$(LYELLOW)Downloading $(YELLOW)19920104_091532.log$(LYELLOW)\t from https://cdn.intra.42.fr/document/document/22781/19920104_091532.log...$(NC)"; \
		wget -q https://cdn.intra.42.fr/document/document/22781/19920104_091532.log --no-check-certificate; \
		if [ -f "Account.hpp" ] && [ -f "tests.cpp" ] && [ -f "19920104_091532.log" ]; then \
    	    echo "$(LGREEN)Download complete.$(NC)"; \
    	else \
    	    echo "$(LRED)Download failed.$(NC)"; \
    	fi; \
	fi;

rmdocs:
	@rm tests.cpp*
	@rm Account.hpp*
	@rm 19920104_091532.log*

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m