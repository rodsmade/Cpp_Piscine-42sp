NAME	= bsp.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

all:	$(NAME)

$(NAME): main.cpp Fixed.o Point.o bsp.o
	$(CC) $(CFLAGS) main.cpp bsp.o Fixed.o Point.o -o $(NAME)

Fixed.o:	Fixed.cpp Fixed.hpp
	$(CC) $(CFLAGS) $< -c -o $@

Point.o:	Point.cpp Point.hpp
	$(CC) $(CFLAGS) $< -c -o $@

bsp.o:	bsp.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f Fixed.o Point.o bsp.o

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(NAME)

.PHONY: all clean fclean re run valgrind