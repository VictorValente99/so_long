NAME = libftprintf.a

SRCS = ft_printf.c \
ft_utils.c 

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -rf
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re