NAME = so_long

HEADERS = include/so_long.h

SRCS = 

GNL_SRCS = 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iincludes -Ilib/minilibx -Ilib/get_next_line -Ilib/libft -Ilib/ft_printf

MLX = -Llib/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = lib/libft/libft.a
LIBFTPRINTF = lib/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/minilibx
	make -C lib/libft
	make -C lib/ft_printf
	$(CC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(MLX) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C lib/minilibx
	make clean -C lib/libft
	make clean -C lib/ft_printf

fclean: clean
	rm -f $(NAME)
	make clean -C lib/minilibx
	make fclean -C lib/libft
	make fclean -C lib/ft_printf

re: fclean all

.PHONY: all clean fclean re