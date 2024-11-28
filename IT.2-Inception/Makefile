# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:03:40 by mbecker           #+#    #+#              #
#    Updated: 2024/11/28 17:29:57 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ENV = srcs/.env
ENV = srcs/example.env

all: $(ENV)
	@echo "$(RED)Have you removed every test entries from requirements ?$(NC)"
	@docker compose -f ./srcs/docker-compose.yml up -d --build

$(ENV):
	@echo "$(YELLOW)Retrieving env file...$(NC)"
	@cp /home/mbecker/inception.env ./srcs/.env

down:
	@docker compose -f ./srcs/docker-compose.yml down

mariadb:
	@echo "$(LYELLOW)Building MARIADB...$(NC)"
	@docker compose -f ./srcs/docker-compose-mariadb.yml up -d --build

nginx:
	@echo "$(LYELLOW)Building NGINX...$(NC)"
	@docker compose -f ./srcs/docker-compose-nginx.yml up -d --build

wordpress:
	@echo "$(LYELLOW)Building WORDPRESS...$(NC)"
	@docker compose -f ./srcs/docker-compose-wordpress.yml up -d --build

clean: down
	@if [ -n "$$(docker ps -q)" ]; then docker stop $$(docker ps -q); fi
	@docker container prune -f

fclean: clean
	@docker system prune -f
	@if [ -f srcs/.env ]; then cp srcs/.env /home/mbecker/inception.env; fi
	@rm -f srcs/.env

re: clean all

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