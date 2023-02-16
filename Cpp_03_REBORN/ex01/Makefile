NAME	= clapclap.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all:	$(NAME)

$(NAME): main.cpp ClapTrap.o
	$(CC) $(CFLAGS) main.cpp ClapTrap.o -o $(NAME)

ClapTrap.o:	ClapTrap.cpp ClapTrap.hpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f ClapTrap.o

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re run valgrind