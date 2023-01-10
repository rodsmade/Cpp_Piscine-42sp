#include "Contact.hpp"

Contact::Contact() {};

Contact::Contact(std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string darkestSecret) {
			this->firstName = firstName;
			this->lastName = lastName;
			this->nickname = nickname;
			this->phoneNumber = phoneNumber;
			this->darkestSecret = darkestSecret;
}

Contact::~Contact() {};

void	Contact::ListDetails() {
	// std::cout << std::setw(20);
	std::cout << "  First Name:\t\t";
	std::cout << this->firstName;
	std::cout << '\n';
	// std::cout << std::setw(20);
	std::cout << "  Last Name:\t\t";
	std::cout << this->lastName;
	std::cout << '\n';
	// std::cout << std::setw(20);
	std::cout << "  Nickname:\t\t";
	std::cout << this->nickname;
	std::cout << '\n';
	// std::cout << std::setw(20);
	std::cout << "  Phone Number:\t\t";
	std::cout << this->phoneNumber;
	std::cout << '\n';
	// std::cout << std::setw(20);
	std::cout << "  Darkest Secret:\t";
	std::cout << this->darkestSecret;
	std::cout << '\n';
}

void	Contact::ListDetailsShort() {
	std::cout << std::setw(10);
	std::cout << this->firstName;
	std::cout << " | ";
	std::cout << std::setw(10);
	std::cout << this->lastName;
	std::cout << " | ";
	std::cout << std::setw(10);
	std::cout << this->nickname;
	std::cout << '\n';
}
