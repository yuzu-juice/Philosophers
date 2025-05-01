NAME	= philo
SRCS	= srcs/main.c
OBJS	= $(SRCS:.c=.o)
HEADERS	= includes/philo.h
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	cd "$(PWD)/libft" && make && cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADERS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cd "$(PWD)/libft" && make clean && cd ..
	rm -f $(OBJS)

fclean: clean
	cd "$(PWD)/libft" && make fclean && cd ..
	rm -f $(NAME)

re: fclean all

norm:
	norminette srcs includes

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./philo

.PHONY: all clean fclean re norm valgrind
