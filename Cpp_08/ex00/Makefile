NAME = find-it.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): main.cpp easyfind.hpp easyfind.tpp
	$(CC) $(CFLAGS) main.cpp easyfind.hpp -o $(NAME)

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind