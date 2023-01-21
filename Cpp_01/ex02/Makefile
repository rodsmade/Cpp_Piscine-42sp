NAME	= refs.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

clean:
	@echo "no object (.o) files to be cleaned..."

fclean: clean
	rm -f $(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re valgrind