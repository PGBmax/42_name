NAMECLIENT = client
NAMESERVER = server

SOURCES = ft_printf/ft_printf.c ft_printf/ft_utils.c

SERVER = normal/server.c
CLIENT = normal/client.c

SERVEROBJ = $(SERVER:.c=.o)
CLIENTOBJ = $(CLIENT:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
OBJECTSALL = $(SERVEROBJ) $(CLIENTOBJ) $(OBJECTS)

SERVERBONUS = bonus/server_bonus.c
CLIENTBONUS = bonus/client_bonus.c

SERVEROBJBONUS = $(SERVERBONUS:.c=.o)
CLIENTOBJBONUS = $(CLIENTBONUS:.c=.o)

OBJECTSALLBONUS = $(SERVEROBJBONUS) $(CLIENTOBJBONUS) $(OBJECTS)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAMECLIENT) $(NAMESERVER)

$(NAMECLIENT): $(OBJECTSALL)
		@$(CC) $(CFLAGS) $(OBJECTS) $(CLIENTOBJ) -o $(NAMECLIENT)
		@printf "\rCompiled Client ✅\n"

$(NAMESERVER): $(OBJECTSALL)
		@$(CC) $(CFLAGS) $(OBJECTS) $(SERVEROBJ) -o $(NAMESERVER)
		@printf "\rCompiled Server ✅\n"

clean:
		@rm -f $(OBJECTSALL)
		@rm -f $(OBJECTSALLBONUS)
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAMESERVER)
		@rm -f $(NAMECLIENT)
		@printf "Cleaned executables ✅\n"

bonus:	$(OBJECTSALLBONUS)
		@$(CC) $(CFLAGS) $(OBJECTS) $(CLIENTOBJBONUS) -o $(NAMECLIENT)
		@$(CC) $(CFLAGS) $(OBJECTS) $(SERVEROBJBONUS) -o $(NAMESERVER)
		@printf "\rCompiled Bonus ✅\n"

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

.PHONY: all bonus clean fclean re scorpionem pgbmax

