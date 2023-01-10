#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getUserInput(std::string prompt) {
	std::string input;

	do {
		// proteger contra ctrl+D aqui, acho q retorna -1 ou algo assim.
		// tratar tb o momento do index, tvz criar outra função sei lá
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input.compare("") == 0);
	return (input);
}

int main()
{
	int index;
	std::string user_input;
	std::string cleanLine;
	bool		pgm_exit = false;
	int		 contacts_count = 0;

	Contact newContact;
	PhoneBook myPhoneBook;

	do {
		std::cout << "Enter `ADD` to add a new contact; `SEARCH` to see details for a contact; or `EXIT` to exit program: ";
		std::cin >> user_input;

		if (user_input.compare("ADD") == 0) {
			std::getline(std::cin, cleanLine);
			newContact.firstName = getUserInput("Insert First Name: ");
			newContact.lastName = getUserInput("Insert Last Name: ");
			newContact.nickname = getUserInput("Insert Nickname: ");
			newContact.phoneNumber = getUserInput("Insert Phone Number: ");
			newContact.darkestSecret = getUserInput("Insert Darkest Secret: ");

			std::cout << '\n';
			std::cout << "New contact details: ";
			newContact.ListDetails();
			std::cout << '\n';

			myPhoneBook.AddNewContact(newContact, contacts_count);
			contacts_count = (contacts_count + 1) % PHONEBOOK_SIZE;

		} else if (user_input.compare("SEARCH") == 0) {
			std::cout << "\n";
			myPhoneBook.ListAllContacts();
			std::cout << '\n';

			bool break_loop = false;
			do {
				std::string indexString = getUserInput("Select a contact by index to see full entry: ");
				std::stringstream s(indexString);
				s >> index;
				if (index >= 1 && index <= 8) {
					myPhoneBook.ListContactByIndex(index - 1);
					std::cout << '\n';
					break_loop = true;
				}
			} while (break_loop == false);
		} else if (user_input.compare("EXIT") == 0) {
			std::cout << "\n";
			std::cout << "Exiting program . . .\n";
			pgm_exit = true;
		}
		std::cout << "\n";
	} while (!pgm_exit);
}
