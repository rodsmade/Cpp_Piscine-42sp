#include <iostream>
#include <string>

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
};

int main()
{
    std::string user_input;
    // bool pgm_exit = false;

    std::string contactFirstName;
    std::string contactLastName;
    std::string contactNickname;
    std::string contactPhoneNumber;
    std::string contactDarkestSecret;
    
    std::cout << "Insert First Name: ";
    std::getline(std::cin, contactFirstName);
    std::cout << "Insert Last Name: ";
    std::getline(std::cin, contactLastName);
    std::cout << "Insert Nickname: ";
    std::getline(std::cin, contactNickname);
    std::cout << "Insert Phone Number: ";
    std::getline(std::cin, contactPhoneNumber);
    std::cout << "Insert Darkest Secret: ";
    std::getline(std::cin, contactDarkestSecret);

    Contact myContact(contactFirstName, contactLastName, contactNickname, contactPhoneNumber, contactDarkestSecret);

    std::cout << "Contato 1:\n";
    std::cout << "firstName: " << myContact.firstName << '\n';
    std::cout << "lastName: " << myContact.lastName << '\n';
    std::cout << "nickname: " << myContact.nickname << '\n';
    std::cout << "phoneNumber: " << myContact.phoneNumber << '\n';
    std::cout << "darkestSecret: " << myContact.darkestSecret << '\n';
    // do {
    //     std::cout << "Enter ADD to add a new contact; SEARCH to see details for a contact; or EXIT to exit program: ";
    //     std::cin >> user_input;

    //     if (user_input.compare("ADD") == 0) {
    //         std::cout << "deu um ADD\n";
    //     } else if (user_input.compare("SEARCH") == 0) {
    //         std::cout << "deu um SEARCH\n";
    //     } else if (user_input.compare("EXIT") == 0) {
    //         std::cout << "deu um EXIT\n";
    //         std::cout << "Exiting program . . .\n";
    //         pgm_exit = true;
    //     }
    //     std::cout << '\n';
    // } while (!pgm_exit);
}
