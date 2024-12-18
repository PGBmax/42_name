NAME = so_long

SOURCES =	src/game.c src/map.c src/ft_check_map.c src/ft_textures.c src/ft_load_textures.c src/ft_loops.c\
			src/ft_parsing.c src/ft_walls.c src/ft_ghost_moves.c src/free_all.c \
			includes/GNL/get_next_line.c includes/GNL/get_next_line_utils.c

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
		@echo "\e[97mCleaned objects ✅\e[97m"

fclean: clean
		@rm -f $(NAME)
		@echo "\e[97mCleaned executables ✅\e[97m"

re : fclean all