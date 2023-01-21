NAME	= brainz.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): main.cpp newZombie.o randomChump.o Zombie.o
	$(CC) $(CFLAGS) main.cpp newZombie.o randomChump.o Zombie.o -o $(NAME)

Zombie.o: Zombie.cpp Zombie.hpp
	$(CC) $(CFLAGS) $< -c -o $@

newZombie.o: newZombie.cpp
	$(CC) $(CFLAGS) $< -c -o $@

randomChump.o: randomChump.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f newZombie.o randomChump.o Zombie.o

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re valgrind