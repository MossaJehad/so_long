LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADERS = so_long.h

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm

SRC = so_long.c \
      so_long_main.c \
      so_long_main_extra.c \
      utils.c \
      get_next_line.c \
      get_next_line_utils.c \
      map_validation.c \
      map_validation2.c \
      map_validation3.c \
      map_validation4.c \
      player_movement.c

OBJ = $(SRC:.c=.o)

all: ${LIBFT} ${NAME}

${LIBFT}:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
