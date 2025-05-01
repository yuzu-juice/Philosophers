NAME	= philo
MAIN = srcs/main.c
SRCS	= srcs/philo.c
HEADERS	= includes/philo.h
MAIN_OBJ = $(MAIN:.c=.o)
OBJS	= $(SRCS:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I includes/

.DEFAULT:	all

all: $(NAME)

# libft
LIBFT = libft
$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(OBJS) -L$(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -f $(MAIN_OBJ) $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette srcs includes

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./philo

.PHONY: all clean fclean re norm valgrind
