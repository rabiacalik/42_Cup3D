NAME = cub3d
CC = gcc

SOURCES = $(wildcard src/*.c src/utils/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
CFLAGS =  -Iinclude -Iminilibx-macos
MLX = libmlx.a -framework OpenGL -framework AppKit

#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) run_mlx
	$(CC) $(OBJECTS) $(CFLAGS) $(MLX) -o $(NAME)

run_mlx:
	cd minilibx-macos && $(MAKE) re
	mv minilibx-macos/libmlx.a ./

clean:
	rm -f $(OBJECTS)
	cd minilibx-macos && $(MAKE) clean

fclean: clean
	rm -rf libmlx.a
	rm -rf $(NAME)

re: fclean all