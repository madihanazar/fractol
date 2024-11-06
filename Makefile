NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = init.c main.c string_utils.c render.c math_utils.c events.c mandelbrot.c julia.c
MLX_DIR = minilibx
MLX_SRC = $(MLX_DIR)/mlx_*.c  # All mlx source files

OBJ = $(SRC:.c=.o)
MLX_OBJ = $(MLX_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_DIR) -lmlx -lz -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(MLX_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
