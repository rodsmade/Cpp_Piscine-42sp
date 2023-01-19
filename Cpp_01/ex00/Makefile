NAME	= brainz
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