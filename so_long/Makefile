NAME = so_long

SOURCES = game.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -Iincludes/ -I$(LIBMLX)/include

LIBMLX = ./MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CFLAGS = -Wall -Werror -Wextra -g

%.o : %.c
	@cc $(CFLAGS) $(INCLUDES) $< -o $@ -c

all	: mlx $(NAME)

mlx :
	@if ls | grep -q "MLX42"; then \
		clear; \
		echo "\033[32;47;1m** MLX42 already exist **\033[1;m"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		make -C ./MLX42/build --no-print-directory -j4; \
		make --directory ./MLX42/build; \
	fi

$(NAME) : $(OBJECTS)
	@cc $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
		@rm -f $(OBJECTS)
		@echo "\033[0;32mCleaned objects ✅\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[0;32mCleaned executables ✅\033[0m"

re : fclean all