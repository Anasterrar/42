NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

SRCS = srcs/ft_putchar.c \
      srcs/ft_putstr.c \
      srcs/ft_strlen.c \
      srcs/ft_swap.c \
      srcs/ft_strcmp.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
