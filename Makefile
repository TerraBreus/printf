NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_det_conversion.c ft_put_char.c ft_put_dec_int.c \
ft_put_str.c ft_put_uns.c ft_put_hex_low.c ft_put_hex_up.c ft_put_point.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS);

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all