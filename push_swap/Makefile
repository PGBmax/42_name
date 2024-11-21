NAME = push_swap

SOURCES =	ft_printf/ft_printf.c ft_printf/ft_utils.c src/push_swap.c \
			src/t_list/ft_lstaddback.c src/t_list/ft_lstaddfront.c src/t_list/ft_lstclear.c src/t_list/ft_lstlast.c src/t_list/ft_lstnew.c src/t_list/ft_lstsize.c \
			src/utils/ft_min_max.c src/utils/ft_others.c src/utils/ft_sort.c src/utils/ft_index.c src/utils/ft_moves.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@printf "\rCompiled push_swap ✅\n"

clean:
		@rm -f $(OBJECTS)
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAME)
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

.PHONY: all clean fclean re scorpionem pgbmax

