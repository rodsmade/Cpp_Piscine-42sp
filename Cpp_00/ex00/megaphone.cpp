#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else {
        for (int i = 1; i < argc; ++i) {
            for (int j = 0; argv[i][j]; ++j) {
                if (std::islower(argv[i][j]))
                    argv[i][j] = std::toupper(argv[i][j]);
            }
            std::cout << argv[i];
        }
    }
    std::cout << "\n";
  
    return 0;
}