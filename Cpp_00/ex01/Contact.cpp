#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(std::string firstName,
				 std::string lastName,
				 std::string nickname,
				 std::string phoneNumber,
				 std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::~Contact(){};

void Contact::ListDetails()
{
	std::cout << "  First Name:\t\t";
	std::cout << this->firstName;
	std::cout << std::endl;
	std::cout << "  Last Name:\t\t";
	std::cout << this->lastName;
	std::cout << std::endl;
	std::cout << "  Nickname:\t\t";
	std::cout << this->nickname;
	std::cout << std::endl;
	std::cout << "  Phone Number:\t\t";
	std::cout << this->phoneNumber;
	std::cout << std::endl;
	std::cout << "  Darkest Secret:\t";
	std::cout << this->darkestSecret;
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
	printShortened(this->firstName);
	std::cout << " | ";
	printShortened(this->lastName);
	std::cout << " | ";
	printShortened(this->nickname);
	std::cout << std::endl;
}
