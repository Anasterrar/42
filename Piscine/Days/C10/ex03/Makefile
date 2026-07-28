NAME = ft_hexdump

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       utils.c \
       convert_to_hex.c \
       ft_hexdump.c \
       errors.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclen: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
