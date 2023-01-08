#include <iostream>
#include <string>

int main()
{
    std::string user_input;
    bool pgm_exit = false;

    do {
        std::cout << "Enter ADD to add a new contact; SEARCH to see details for a contact; or EXIT to exit program: ";
        std::cin >> user_input;

        if (user_input.compare("ADD") == 0) {
            std::cout << "deu um ADD\n";
        } else if (user_input.compare("SEARCH") == 0) {
            std::cout << "deu um SEARCH\n";
        } else if (user_input.compare("EXIT") == 0) {
            std::cout << "deu um EXIT\n";
            std::cout << "Exiting program . . .\n";
            pgm_exit = true;
        }
        std::cout << '\n';
    } while (!pgm_exit);
}
