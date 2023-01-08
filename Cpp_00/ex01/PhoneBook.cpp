#include "PhoneBook.hpp"

Contact allContacts[PHONEBOOK_SIZE];

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void PhoneBook::ListContactByIndex(int index) {
    allContacts[index].ListDetails();
}

void PhoneBook::ListAllContacts() {
    std::cout << "Index | First Name | Last Name | Nickname\n";

    for (int i = 0; i < PHONEBOOK_SIZE; i++) {
        std::cout << i << " | ";
        allContacts[i].ListDetailsShort();
        std::cout << '\n';
    }
}

void PhoneBook::AddNewContact(Contact newContact, int index) {
    allContacts[index % PHONEBOOK_SIZE] = newContact;
}