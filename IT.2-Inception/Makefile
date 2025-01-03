# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:03:40 by mbecker           #+#    #+#              #
#    Updated: 2024/12/29 16:52:51 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENV =	srcs/.env
DATA =	/home/mbecker/data

VOLUMES =	$(DATA)/mariadb_data \
			$(DATA)/wordpress_data \
			$(DATA)/prometheus_data

all: $(ENV) $(VOLUMES)
	@echo "$(YELLOW)Starting containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml up -d --build

$(ENV):
	@echo "$(YELLOW)Retrieving environment file (example.env)...$(NC)"
	@cp example.env srcs/.env

$(VOLUMES):
	@echo "$(YELLOW)Creating volumes directories...$(NC)"
	@mkdir -p $(VOLUMES)

down:
	@echo "$(RED)Stopping containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml down

clean: down
	@echo "$(RED)Removing containers...$(NC)"
	@if [ -n "$$(docker ps -q)" ]; then docker stop $$(docker ps -q); fi
	@docker container prune -f

fclean: clean
	@echo "$(RED)Removing all images...$(NC)"
	@docker rmi $$(docker images -q)
	@docker system prune -f
	@echo "$(RED)Removing inception volumes...$(NC)"
	@docker compose -f srcs/docker-compose.yml down -v
	@echo "$(RED)Removing environment file from srcs...$(NC)"
	@rm -f srcs/.env

erase_data:
	@echo "$(RED)Removing local data ($(DATA))...$(NC)"
	@sudo rm -rf $(DATA)

re: fclean all

logs:
	@docker compose -f srcs/docker-compose.yml logs

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