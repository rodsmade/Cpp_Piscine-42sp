NAME	= ambush.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME): main.cpp HumanA.o HumanB.o Weapon.o
	$(CC) $(CFLAGS) main.cpp HumanA.o HumanB.o Weapon.o -o $(NAME)

HumanA.o: HumanA.cpp HumanA.hpp
	$(CC) $(CFLAGS) $< -c -o $@

HumanB.o: HumanB.cpp HumanB.hpp
	$(CC) $(CFLAGS) $< -c -o $@

Weapon.o: Weapon.cpp Weapon.hpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f HumanA.o HumanB.o Weapon.o

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re valgrind