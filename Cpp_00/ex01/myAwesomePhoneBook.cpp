#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getUserInput(std::string prompt) {
    std::string input;

    do {
        std::cout << prompt;
        std::getline(std::cin, input);
    } while (input.compare("") == 0);
    return (input);
}

int main()
{
    std::string user_input;
    std::string cleanLine;
    bool        pgm_exit = false;
    int         contacts_count = 0;

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

            std::cout << "New contact details: ";
            newContact.ListDetails();

            myPhoneBook.AddNewContact(newContact, contacts_count);
            contacts_count = (contacts_count + 1) % PHONEBOOK_SIZE;

        } else if (user_input.compare("SEARCH") == 0) {
            std::cout << "deu um SEARCH\n";
        } else if (user_input.compare("EXIT") == 0) {
            std::cout << "deu um EXIT\n";
            std::cout << "Exiting program . . .\n";
            pgm_exit = true;
        }
        std::cout << "\n\n";
    } while (!pgm_exit);
}
