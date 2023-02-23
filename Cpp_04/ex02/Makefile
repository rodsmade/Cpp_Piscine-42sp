NAME	= animales.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SOURCES = Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all:	$(NAME)

$(NAME): main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(NAME)

%.o:	%.cpp %.hpp
	$(CC) $(CFLAGS) $< -c -o $@

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