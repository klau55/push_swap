SRCS = operations.c push_swap.c node_ops.c helpers.c costs.c 4_to_n.c ft_split.c
OBJ = $(SRCS:.c=.o)
NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re