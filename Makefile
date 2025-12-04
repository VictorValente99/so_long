NAME = so_long

HEADERS = include/so_long.h

SRCS = src/main.c \
       src/game/cleanup.c \
       src/game/game_init.c \
       src/input/key_handler.c \
       src/map/map_elements_validator.c \
       src/map/map_path_validator.c \
       src/map/map_receive.c \
       src/map/map_struct_validator.c \
       src/map/map_utils.c \
       src/render/render.c \
       src/sprites/sprite_loader.c \
       utils/free_sprites.c \
       utils/put_error.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -Ilibs/minilibx -Ilibs/get_next_line -Ilibs/lib_ft -Ilibs/ft_printf

MLX = -Llibs/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = libs/libft/libft.a
LIBFTPRINTF = libs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libs/minilibx
	make -C libs/libft
	make -C libs/ft_printf
	$(CC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(MLX) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libs/minilibx
	make clean -C libs/libft
	make clean -C libs/ft_printf

fclean: clean
	rm -f $(NAME)
	make clean -C libs/minilibx
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re