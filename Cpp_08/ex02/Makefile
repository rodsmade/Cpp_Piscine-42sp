NAME = ninjaturtles.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(SOURCES) MutantStack.hpp MutantStack.tpp
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) $< -c -o $@

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run valgrind