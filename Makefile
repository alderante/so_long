CC = cc

NAME = so_long

SRC = src/so_long.c \
		src/map.c \
		src/map_checker.c \
		src/map_movement.c \
		src/so_long_utils.c

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a -lX11 -lXext -lm

all: $(NAME)

$(NAME): 
	make -C libft
	$(CC) $(SRC) $(MLX) $(LIBFT) -o $(NAME) -g
	@echo "\e[92m$(NAME) compiled\e[0m"

re:	fclean all

clean:
	make clean -C libft
	
fclean: clean 
	make fclean -C libft
	rm -rf $(NAME)

bonus:

.PHONY: all re clean fclean bonus

#.SILENT:
