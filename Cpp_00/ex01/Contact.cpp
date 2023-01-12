#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
{
}

Contact::~Contact(){};

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
};
void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
};
void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
};
void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
};
void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
};

void Contact::ListDetails()
{
	std::cout << "  First Name:\t\t";
	std::cout << this->_firstName;
	std::cout << std::endl;
	std::cout << "  Last Name:\t\t";
	std::cout << this->_lastName;
	std::cout << std::endl;
	std::cout << "  Nickname:\t\t";
	std::cout << this->_nickname;
	std::cout << std::endl;
	std::cout << "  Phone Number:\t\t";
	std::cout << this->_phoneNumber;
	std::cout << std::endl;
	std::cout << "  Darkest Secret:\t";
	std::cout << this->_darkestSecret;
	std::cout << std::endl;
}

void printShortened(std::string str)
{
	std::string strCopy;

	std::cout << std::setw(10);
	if (str.size() > 10)
	{
		strCopy = str.substr(0, 10);
		strCopy[9] = '.';
		std::cout << strCopy;
	}
	else
	{
		std::cout << str;
	}
}

void Contact::ListDetailsShort()
{
	printShortened(this->_firstName);
	std::cout << " | ";
	printShortened(this->_lastName);
	std::cout << " | ";
	printShortened(this->_nickname);
	std::cout << std::endl;
}
