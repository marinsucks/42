CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = $(wildcard *.c)
# OBJ = $(SRC:.c=.o)

FUNCTION_NAME = $(firstword $(MAKECMDGOALS))

git:
	@echo "Adding all files to staging area..."
	@git add .
	git commit -m "$m"

all: comp exe

comp: $(SRC)
	@echo "Compiling all .c files..."
	@$(CC) $(CFLAGS) -o libft $(SRC)

exe: 
	@echo "Executing libft..."
	@./libft

ft_%:
	@echo "Compiling $@.c..."
	@$(CC) -Wall -Werror -Wextra $@.c -o a.out
	@./a.out

clean:
	@echo "Removing executables..."
	rm -f libft a.out

