# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:03:40 by mbecker           #+#    #+#              #
#    Updated: 2025/04/06 22:37:05 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENV =	srcs/.env
DATA =	srcs/volumes

VOLUMES =	$(DATA)/mariadb_data \
			$(DATA)/wordpress_data \
			$(DATA)/prometheus_data

all: $(ENV) volumes
	@echo "$(YELLOW)Starting containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml up -d --build

$(ENV):
	@echo "$(YELLOW)Retrieving environment file (example.env)...$(NC)"
	@cp srcs/example.env srcs/.env

volumes:
	@echo "$(YELLOW)Creating volumes directories...$(NC)"
	@mkdir -p $(VOLUMES)

down:
	@echo "$(RED)Stopping containers...$(NC)"
	@docker compose -f srcs/docker-compose.yml down

clean: down
	@echo "$(RED)Removing containers related to the project...$(NC)"
	@docker compose -f srcs/docker-compose.yml rm -f

fclean: clean
	@echo "$(RED)Removing inception images...$(NC)"
	@docker compose -f srcs/docker-compose.yml down --rmi all
	@docker compose -f srcs/docker-compose.yml down -v
	@echo "$(RED)Removing inception environment file...$(NC)"
	@if [ -f srcs/.env ]; then rm -f srcs/.env; fi
	@echo "$(RED)Removing inception volumes...$(NC)"
	@if [ -d $(DATA) ]; then rm -rf $(DATA); fi

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