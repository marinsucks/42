# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:03:40 by mbecker           #+#    #+#              #
#    Updated: 2024/12/02 17:11:32 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!ENV =	srcs/.env
ENV =	srcs/example.env
DATA =	/home/mbecker/data
VOLUMES = $(DATA)/mariadb_data $(DATA)/wordpress_data

all: $(ENV) $(VOLUMES)
	@echo "$(RED)REMOVE US:$(NC)"
	@echo "$(LRED)  - $(RED)example.env$(LRED) (replace with .env in Makefile)$(NC)"
	@echo "$(LRED)  - $(RED)rm -rf $(DATA)$(NC)"
	@echo "$(YELLOW)Starting containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml up -d --build
	@docker compose -f srcs/docker-compose.yml logs

$(ENV):
	@echo "$(YELLOW)Retrieving environment file...$(NC)"
	@cp /home/mbecker/inception.env srcs/.env

$(VOLUMES):
	@echo "$(YELLOW)Creating volumes directories...$(NC)"
	@mkdir -p $(DATA)/mariadb_data
	@mkdir -p $(DATA)/wordpress_data

down:
	@echo "$(RED)Stopping containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml down

clean: down
	@echo "$(RED)Removing containers...$(NC)"
	@if [ -n "$$(docker ps -q)" ]; then docker stop $$(docker ps -q); fi
	@docker container prune -f

fclean: clean
	@echo "$(RED)Removing images...$(NC)"
	@docker system prune -f
	@echo "$(RED)Removing volumes...$(NC)"
	@docker compose -f srcs/docker-compose.yml down -v
	@sudo rm -rf $(DATA) #!REMOVE ME
	@echo "$(RED)Removing environment file from srcs...$(NC)"
	@if [ -f srcs/.env ]; then cp srcs/.env $$HOME/inception.env; fi
	@rm -f srcs/.env

re: fclean all

.PHONY : all clean re 

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
BLUE =\033[1;34m
LBLUE =\033[0;34m
GREY =\033[1;37m
NC =\033[0m