CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
FILES = $(shell find . -name '*.c')
OBJ = $(FILES:%.c=%.o)

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

all: firstecho ${NAME}

firstecho:
	@echo "Compiling Libft..."

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "Libft compiled."

clean:
	@find . -name '*.o' -delete
	@echo "Libft cleaning."

fclean: clean
	@if [ -e $(NAME) ]; then rm $(NAME); fi
	@echo "Libft Deleted."

re: clean all

.PHONY:
	all ofile clean
