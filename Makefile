NAME = so_long

SRCS = so_long.c \
		map.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXLIB = MLX42/build/libmlx42.a
LIBMLX = ./MLX42
FLAGSMLX = -ldl -lglfw -pthread -lm

LIBFT = ./libft/libft.a

all: $(LIBMLX) $(MLXLIB) $(NAME)

$(LIBMLX):
	git clone https://github.com/codam-coding-college/MLX42.git && \
	cd MLX42 && \
	cmake -B build && \
	cmake --build build -j4

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLXLIB):
	@cmake $(LIBMLX) -DDEBUG=1 -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLXLIB) $(FLAGSMLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install_mlx: $(LIBMLX) $(MLXLIB)

clean:
	make clean -C libft
	rm -f $(OBJS)
	rm -rf $(LIBMLX)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -rf $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re