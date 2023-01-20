NAME	= brainz.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): main.cpp zombieHorde.o Zombie.o
	$(CC) $(CFLAGS) main.cpp zombieHorde.o Zombie.o -o $(NAME)

Zombie.o: Zombie.cpp Zombie.hpp
	$(CC) $(CFLAGS) $< -c -o $@

zombieHorde.o: zombieHorde.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f zombieHorde.o Zombie.o

fclean: clean
	rm -f $(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all $(NAME) clean fclean valgrind