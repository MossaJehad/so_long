NAME = so_long
SRC = so_long.c utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
