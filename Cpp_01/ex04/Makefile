NAME	= sed.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

clean:
	@echo "no .o files to be cleaned. . ."

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) hello.txt abc def

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all $(NAME) clean fclean valgrind