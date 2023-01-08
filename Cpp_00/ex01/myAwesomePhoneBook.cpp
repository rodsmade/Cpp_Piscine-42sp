#include <iostream>
#include <string>

const int   PHONEBOOK_SIZE = 8;

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

        Contact(std::string firstName,
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

        void    ListDetails() {
            std::cout << this->firstName << " | "
                        << this->lastName << " | "
                        << this->nickname << " | "
                        << this->phoneNumber << " | "
                        << this->darkestSecret;
        }
};

class PhoneBook {
    public:
        Contact allContacts[PHONEBOOK_SIZE];

        void ListAllContacts() {
            std::cout << "Index | First Name | Last Name | Nickname | Phone Number | Darkest Secret";

            for (int i = 0; i < PHONEBOOK_SIZE; i++) {
                std::cout << i << " | ";
                allContacts[i].ListDetails();
                std::cout << '\n';
            }
        }
};

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
    bool pgm_exit = false;

    std::string contactFirstName;
    std::string contactLastName;
    std::string contactNickname;
    std::string contactPhoneNumber;
    std::string contactDarkestSecret;
    std::string cleanLine;
    

    do {
        std::cout << "Enter `ADD` to add a new contact; `SEARCH` to see details for a contact; or `EXIT` to exit program: ";
        std::cin >> user_input;

        if (user_input.compare("ADD") == 0) {
            std::getline(std::cin, cleanLine);
            contactFirstName = getUserInput("Insert First Name: ");
            contactLastName = getUserInput("Insert Last Name: ");
            contactNickname = getUserInput("Insert Nickname: ");
            contactPhoneNumber = getUserInput("Insert Phone Number: ");
            contactDarkestSecret = getUserInput("Insert Darkest Secret: ");

            Contact myContact(contactFirstName, contactLastName, contactNickname, contactPhoneNumber, contactDarkestSecret);

            myContact.ListDetails();
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
