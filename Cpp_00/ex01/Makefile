
# c++ -Wall -Wextra -Werror -std=c++98 myAwesomePhoneBook.cpp PhoneBook.cpp Contact.cpp

all: myAwesomePhoneBook.out

myAwesomePhoneBook.out: PhoneBook.cpp Contact.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -g3 myAwesomePhoneBook.cpp PhoneBook.cpp Contact.cpp -o myAwesomePhoneBook.out

clean:
	rm -f myAwesomePhoneBook.o

fclean: clean
	rm -f myAwesomePhoneBook.out