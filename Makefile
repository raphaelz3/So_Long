NAME = so_long

FLAGS = -Wall -Wextra -Werror -g3

MINILIBX = -Imlx -lX11 -lXext

MLX = mlx/libmlx_Linux.a

FT_PRINTF_DIR = ft_printf

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRCS =	map.c\
		main.c\
		get_next_line_utils.c\
		get_next_line.c\
		definitions.c\
		mov.c\
		map_validation.c\
		set_image.c\
		colection.c\
		path_validation.c\
		exit.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX):
	$(MAKE) -C ./mlx

$(NAME): $(MLX) $(FT_PRINTF) $(OBJ)
	cc $(FLAGS) $(SRCS) $(MLX) $(MINILIBX) $(FT_PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C ./ft_printf

fclean:clean
	rm -f $(NAME)
	make fclean -C ./ft_printf
	make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re ft_printf
