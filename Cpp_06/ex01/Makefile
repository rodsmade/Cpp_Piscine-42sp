NAME = serialization.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SOURCES = Data.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): main.cpp $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(NAME)

%.o:	%.cpp %.hpp
	$(CC) $(CFLAGS) $< -c -o $@

run: all
	./$(NAME) nan

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run