
# c++ -Wall -Wextra -Werror -std=c++98 myAwesomePhoneBook.cpp PhoneBook.cpp Contact.cpp

all: myAwesomePhoneBook.out

myAwesomePhoneBook.out: PhoneBook.o Contact.o myAwesomePhoneBook.cpp
	c++ -Wall -Wextra -Werror -std=c++98 myAwesomePhoneBook.cpp PhoneBook.cpp Contact.cpp -o myAwesomePhoneBook.out

PhoneBook.o:	PhoneBook.cpp PhoneBook.hpp
	c++ -Wall -Wextra -Werror -std=c++98 -c PhoneBook.cpp -o PhoneBook.o

Contact.o:	Contact.cpp Contact.hpp
	c++ -Wall -Wextra -Werror -std=c++98 -c Contact.cpp -o Contact.o

clean:
	rm -f PhoneBook.o Contact.o

fclean: clean
	rm -f myAwesomePhoneBook.out