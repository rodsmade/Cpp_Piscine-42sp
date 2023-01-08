all: myAwesomePhoneBook.o
	c++ -Wall -Wextra -Werror -std=c++98 myAwesomePhoneBook.cpp -o myAwesomePhoneBook.out

myAwesomePhoneBook.o: myAwesomePhoneBook.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c myAwesomePhoneBook.cpp -o myAwesomePhoneBook.o

clean:
	rm -f myAwesomePhoneBook.o

fclean: clean
	rm -f myAwesomePhoneBook.out