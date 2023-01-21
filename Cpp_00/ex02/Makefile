
NAME=tests.out

all: $(NAME)

$(NAME): Account.o tests.cpp
	c++ -Wall -Wextra -Werror -std=c++98 Account.o tests.cpp -o $(NAME)

Account.o:	Account.cpp Account.hpp
	c++ -Wall -Wextra -Werror -std=c++98 -c -O2 Account.cpp -o Account.o

clean:
	rm -f Account.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re