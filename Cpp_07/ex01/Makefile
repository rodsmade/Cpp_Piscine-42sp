NAME = what.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

# SOURCES = Base.cpp A.cpp B.cpp C.cpp functions.cpp
# OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): main.cpp iter.hpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

# %.o:	%.cpp %.hpp
# 	$(CC) $(CFLAGS) $< -c -o $@

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