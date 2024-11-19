NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_puthexa.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

all:	 $(NAME) clean

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus