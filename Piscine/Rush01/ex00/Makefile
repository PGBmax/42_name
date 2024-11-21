NAME = skycrapper

SOURCES =	ft_printf/ft_printf.c ft_printf/ft_utils.c main.c management.c verif.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
		@printf "\rCompiled $(NAME) ✅\n"

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

