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
	std::cout << this->firstName << " | "
				<< this->lastName << " | "
				<< this->nickname << " | "
				<< this->phoneNumber << " | "
				<< this->darkestSecret;
}

void	Contact::ListDetailsShort() {
	std::cout << this->firstName << " | "
				<< this->lastName << " | "
				<< this->nickname;
	std::cout << '\n';
}
