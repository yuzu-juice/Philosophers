NAME	= philo
SRCS	= srcs/main.c\
			srcs/init.c\
			srcs/error.c\
			srcs/philo.c\
			srcs/thread.c\
			srcs/time.c\
			srcs/print.c\
			srcs/watchdog.c\
			srcs/utils/ft_atouint.c\
			srcs/utils/ft_calloc.c\
			srcs/utils/ft_putstr.c
OBJS	= $(SRCS:.c=.o)
HEADERS	= includes/philo.h\
			includes/error_messages.h\
			includes/utils.h\
			includes/exit.h\
			includes/result.h\
			includes/thread.h\
			includes/time.h\
			includes/print.h\
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread -I includes

%.o: %.c $(HEADERS))
	$(CC) $(CFLAGS) -c $< -o $@ -I includes

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette srcs includes

INTEGRATION_TESTS = $(wildcard tests/*.test.sh)
integration: all
	@echo "Running integration tests..."
	@for test in $(INTEGRATION_TESTS); do \
		if chmod 755 $${test} && $${test}; then \
			echo "\033[32mPassed: $${test}\033[0m";\
		else \
			echo "\033[31mFailed: $${test}\033[0m"; \
			exit 1; \
		fi; \
	done
	@echo "⭐️\033[32mPassed all integration tests!\033[0m⭐️"

tests: norm integration

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./philo

.PHONY: all clean fclean re norm integration tests valgrind
