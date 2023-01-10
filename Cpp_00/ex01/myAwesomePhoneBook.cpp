#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getUserInput(std::string prompt)
{
	std::string input;

	if (std::cin.eof() == false) {
		do
		{
			std::cout << prompt;
			std::getline(std::cin, input);
		} while (input.compare("") == 0 && std::cin.eof() == false);
	}
	return (input);
}

int main()
{
	int index;
	std::string user_input;
	std::string cleanLine;
	bool pgm_exit = false;
	int contacts_count = 0;

	Contact newContact;
	PhoneBook myPhoneBook;

	do
	{
		user_input = getUserInput("Enter `ADD` to add a new contact; `SEARCH` to see details for a contact; or `EXIT` to exit program: ");

		if (user_input.compare("ADD") == 0)
		{
			newContact.firstName = getUserInput("Insert First Name: ");
			newContact.lastName = getUserInput("Insert Last Name: ");
			newContact.nickname = getUserInput("Insert Nickname: ");
			newContact.phoneNumber = getUserInput("Insert Phone Number: ");
			newContact.darkestSecret = getUserInput("Insert Darkest Secret: ");

			std::cout << std::endl;

			myPhoneBook.AddNewContact(newContact, contacts_count);
			contacts_count = (contacts_count + 1) % PHONEBOOK_SIZE;
		}
		else if (user_input.compare("SEARCH") == 0)
		{
			std::cout << std::endl;
			myPhoneBook.ListAllContacts();
			std::cout << std::endl;

			bool break_loop = false;
			do
			{
				std::string indexString = getUserInput("Select a contact by index to see full entry: ");
				std::cout << std::endl;

				std::stringstream s(indexString);
				s >> index;
				if (index >= 1 && index <= 8)
				{
					myPhoneBook.ListContactByIndex(index - 1);
					std::cout << std::endl;
					break_loop = true;
				}
			} while (break_loop == false);
		}
		else if (user_input.compare("EXIT") == 0)
		{
			std::cout << std::endl;
			std::cout << "Exiting program . . ." << std::endl;
			pgm_exit = true;
		}
		std::cout << std::endl;
	} while (!pgm_exit && std::cin.eof() == false);
}
