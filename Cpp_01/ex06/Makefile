NAME	= HarlFilter
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all:	$(NAME)

$(NAME): main.cpp Harl.o
	$(CC) $(CFLAGS) main.cpp Harl.o -o $(NAME)

Harl.o:	Harl.cpp Harl.hpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f Harl.o

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re run valgrind