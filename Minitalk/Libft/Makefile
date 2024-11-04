NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SOURCESALL = $(SOURCES) $(BONUS)

OBJECTS = $(SOURCES:.c=.o)

OBJECTSALL = $(SOURCESALL:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@printf "\rCompiled mandatory ✅"

BAR_LENGTH := 20
ifeq ($(MAKECMDGOALS),bonus)
	TOTAL_FILES := $(words $(SOURCESALL))
else
	TOTAL_FILES := $(words $(SOURCES))
endif
COMPILED_FILES := 0

scorpionem :
	@printf "\033[0;34m"
	@echo " ▗▄▄▖▗▞▀▘ ▄▄▄   ▄▄▄ ▄▄▄▄  ▄  ▄▄▄  ▄▄▄▄  ▗▞▀▚▖▄▄▄▄"
	@echo "▐▌   ▝▚▄▖█   █ █    █   █ ▄ █   █ █   █ ▐▛▀▀▘█ █ █"
	@echo " ▝▀▚▖    ▀▄▄▄▀ █    █▄▄▄▀ █ ▀▄▄▄▀ █   █ ▝▚▄▄▖█   █ "
	@echo "▗▄▄▞▘               █     █                        "
	@printf "\033[0m"

%.o : %.c
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(eval PROGRESS_PERCENT := $(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	@$(eval FILLED_BAR_LENGTH := $(shell echo $$(($(PROGRESS_PERCENT) * $(BAR_LENGTH) / 100))))
	@printf "\rCompiling [\033[0;32m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "◦"; done
	@printf "🟡"
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf "•"; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
		@ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTSALL)
		@ar rcs $(NAME) $(OBJECTSALL)
		@printf "\rCompiled bonus ✅"

clean:
		@rm -f $(OBJECTS) $(OBJECTSALL)
		@printf "Cleaned objects ✅\n"

fclean: clean
		@rm -f $(NAME)
		@printf "Cleaned everything ✅\n"

re: fclean all

.PHONY: all bonus clean fclean re scorpionem

