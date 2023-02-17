NAME	= badgalriri.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 -g

SOURCES	= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJECTS	= $(patsubst %.cpp,%.o,$(SOURCES))


all:	$(NAME)

$(NAME): main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(NAME)

%.o : %.cpp %.hpp
	$(CC) -c $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re run valgrind