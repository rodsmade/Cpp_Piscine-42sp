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
	std::cout << this->firstName;
	std::cout << " | ";
	std::cout << this->lastName;
	std::cout << " | ";
	std::cout << this->nickname;
	std::cout << " | ";
	std::cout << this->phoneNumber;
	std::cout << " | ";
	std::cout << this->darkestSecret;
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
