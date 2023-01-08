all: megaphone.out

megaphone.out: megaphone.o
	c++ -Wall -Wextra -Werror -std=c++98 megaphone.o -o megaphone.out

megaphone.o: megaphone.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c megaphone.cpp -o megaphone.o

clean:
	rm -f megaphone.o

fclean: clean
	rm -f megaphone.out