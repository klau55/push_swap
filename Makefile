SRCS = operations.c operations_2.c operations_3.c \
node_ops_2.c node_ops_3.c node_ops_4.c node_ops.c  \
helpers.c helpers_2.c 4_to_n_2.c 4_to_n_3.c 4_to_n.c  \
error_handling.c ft_split.c push_swap.c

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