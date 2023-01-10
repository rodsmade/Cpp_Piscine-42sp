#include "PhoneBook.hpp"

Contact allContacts[PHONEBOOK_SIZE];

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void PhoneBook::ListContactByIndex(int index) {
	std::cout << "Entry " << index + 1 << ":\n";
	allContacts[index].ListDetails();
}

void PhoneBook::ListAllContacts() {
	std::cout << std::setw(10);
	std::cout << "Index";
	std::cout << " | ";
	std::cout << std::setw(10);
	std::cout << "First Name";
	std::cout << " | ";
	std::cout << std::setw(10);
	std::cout << "Last Name";
	std::cout << " | ";
	std::cout << std::setw(10);
	std::cout << "Nickname";
	std::cout << '\n';

	for (int i = 0; i < PHONEBOOK_SIZE; i++) {
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << " | ";
		allContacts[i].ListDetailsShort();
	}
}

void PhoneBook::AddNewContact(Contact newContact, int index) {
	allContacts[index % PHONEBOOK_SIZE] = newContact;
}