CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = $(wildcard *.c)

FUNCTION_NAME = $(firstword $(MAKECMDGOALS))

all: comp exe

comp: $(SRC)
	@echo "Compiling all .c files..."
	@$(CC) $(CFLAGS) -o libexe $(SRC)

ft_%:
	@echo "Compiling $@.c..."
	@$(CC) $(CFLAGS) $@.c -o a.out
	@./a.out

func: compmain exe

compmain:
	@echo "Compiling *.c (except main)..."
	@ls *.c | grep -v "main.c" | xargs $(CC) $(CFLAGS) -g -o libexe

exe: 
	@echo "Executing libft..."
	@./libexe

clean:
	@echo "Removing executables..."
	rm -rf a.out libexe a.out.dSYM *.o

git:
	@echo "Adding all files to staging area..."
	@git add .
	git commit -m "$m"

norm:
	@ls *.c *.h | grep -v -e "main.c" -e "oldmain.c" | xargs norminette