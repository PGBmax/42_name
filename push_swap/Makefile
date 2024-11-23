NAME = push_swap
NAMEBONUS = checker

SOURCES =	ft_printf/ft_printf.c ft_printf/ft_utils.c  \
			src/t_list/ft_lstaddback.c src/t_list/ft_lstaddfront.c src/t_list/ft_lstclear.c src/t_list/ft_lstlast.c src/t_list/ft_lstnew.c src/t_list/ft_lstsize.c \
			src/utils/ft_index.c src/utils/ft_list.c src/utils/ft_min_max.c src/utils/ft_moves.c src/utils/ft_others.c src/utils/ft_sort.c src/utils/ft_split.c src/utils/ft_substr.c

SOURCESMAIN = src/push_swap.c

SOURCESBONUS = bonus/ft_checker_bonus.c bonus/ft_utils_bonus.c bonus/GNL/get_next_line_bonus.c bonus/GNL/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTSMAIN = $(SOURCESMAIN:.c=.o)
OBJECTSBONUS = $(SOURCESBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSMAIN)
		@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSMAIN) -o $(NAME)
		@printf "\rCompiled push_swap ✅\n"

clean:
		@rm -f $(OBJECTS) $(OBJECTSBONUS) $(OBJECTSMAIN)
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAME) $(NAMEBONUS)
		@printf "Cleaned executables ✅\n"

re: fclean all

bonus: $(OBJECTS) $(OBJECTSBONUS)
		@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSBONUS) -o $(NAMEBONUS)
		@printf "\rCompiled checker ✅\n"

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

manualouest :
	@printf "\e[91m𝔪𝔞𝔫𝔲𝔞𝔩𝔬𝔲𝔢𝔰𝔱\n\e[97m"

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


credits : scorpionem pgbmax manualouest izzokz ghostizzokz toro_gi chazzup

.PHONY: all clean fclean re scorpionem pgbmax manualouest izzokz ghostizzokz toro_gi chazzup credits

