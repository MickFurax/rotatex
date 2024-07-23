NAME = rotatex

CC = gcc

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
