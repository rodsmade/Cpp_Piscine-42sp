NAME	= sed.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all:	$(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

clean:
	@echo "no .o files to be cleaned. . ."

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) tests/hello.txt ee EE

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) tests/hello.txt ee EE

.PHONY: all clean fclean re run valgrind