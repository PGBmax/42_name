SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_strchr.c ft_memcmp.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_atoi.c ft_strlcat.c ft_strlcpy.c

OBJ = $(SRC:.c=.o)

OBJO = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memmove.o ft_memchr.o ft_strchr.o ft_memcmp.o ft_toupper.o ft_tolower.o ft_strrchr.o ft_atoi.o ft_strlcat.o ft_strlcpy.o

CFLAGS = -Werror -Wextra -Wall -g3

NAME = libft.a

$(NAME): $(OBJ)
		 ar rc $(NAME) $(OBJ)

all:	 $(OBJ) $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
