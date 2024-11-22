NAME = push_swap
NAMEBONUS = checker

SOURCES =	ft_printf/ft_printf.c ft_printf/ft_utils.c src/push_swap.c \
			src/t_list/ft_lstaddback.c src/t_list/ft_lstaddfront.c src/t_list/ft_lstclear.c src/t_list/ft_lstlast.c src/t_list/ft_lstnew.c src/t_list/ft_lstsize.c \
			src/utils/ft_min_max.c src/utils/ft_others.c src/utils/ft_sort.c src/utils/ft_index.c src/utils/ft_moves.c

SOURCESBONUS = bonus/

OBJECTS = $(SOURCES:.c=.o)
OBJECTSBONUS = $(SOURCESBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@printf "\rCompiled push_swap ✅\n"

clean:
		@rm -f $(OBJECTS) $(OBJECTSBONUS)
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAME) $(NAMEBONUS)
		@printf "Cleaned executables ✅\n"

re: fclean all


scorpionem :
	@printf "\033[0;34m\n"
	@echo " ▗▄▄▖▗▞▀▘ ▄▄▄   ▄▄▄ ▄▄▄▄  ▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▄▄▄▄"
	@echo "▐▌   ▝▚▄▖█   █ █    █   █ ▄ █   █ █   █ ▐▛▀▀▘█ █ █"
	@echo " ▝▀▚▖    ▀▄▄▄▀ █    █▄▄▄▀ █ ▀▄▄▄▀ █   █ ▝▚▄▄▖█   █ "
	@echo "▗▄▄▞▘               █     █                        "
	@printf "\033[0m\n"

pgbmax :
	@printf "\033[0;34m\n"
	@echo "▄▄▄▄  ▗▄▖ ▗▖   ▄▄▄▄  ▗▞▀▜▌▄   ▄" 
	@echo "█   █▐▌ ▐▌▐▌   █ █ █ ▝▚▄▟▌ ▀▄▀ "
	@echo "█▄▄▄▀ ▝▀▜▌▐▛▀▚▖█   █      ▄▀ ▀▄"
	@echo "█    ▐▙▄▞▘▐▙▄▞▘                "
	@echo "▀"
	@printf "\033[0m\n"

izzokz :
	@printf "\033[0;31m\n"
	@echo "Izzokz on Souncloud, Follow me :)"
	@printf "\033[0;1m\n"
	@echo "https://soundcloud.com/Izzokz"
	@printf "\033[0m\n"

ghostizzokz :
	@printf "\033[0;33m\n"
	@echo "Ghostizzokz on Youtube, I sometimes repost my own musics, subscribe :)"
	@printf "\033[0m\n"

toro_gi :
	@printf "\033[0;36m\n"
	@echo "twitch.tv/toro-gi, follow me on twitch, i wanna be twitch partner !"
	@printf "\033[0m\n"

chazzup :
	@printf "\033[0;36m\n"
	@echo "twitch.tv/chazzup"
	@printf "\033[0m\n"

.PHONY: all clean fclean re scorpionem pgbmax izzokz ghostizzokz toro_gi chazzup

