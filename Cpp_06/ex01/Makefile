NAME = serialization.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SOURCES = Data.cpp
OBJECTS = $(SOURCES:.cpp=.o)
FUNCTIONS = serialize.cpp deserialize.cpp

all: $(NAME)

$(NAME): main.cpp $(OBJECTS) $(FUNCTIONS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) $(FUNCTIONS) -o $(NAME)

%.o:	%.cpp %.hpp
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