NAME = ft_cat

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       ft_utils.c \
       ft_cat.c \
       error.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
