#include <iostream>
#include <fstream>
#include <string>

// int main() {
// 	std::string line;
// 	std::ifstream myfile("hello.txt");

// 	if (myfile.is_open()) {
// 		while (myfile.good()) {
// 			std::getline (myfile, line);

// 			std::cout << line << '\n';
// 			line.find("fl");

// 		}
// 	}
// 	else
// 		std::cout << "file not open" << std::endl;

// 	myfile.close();
// }

// int main() {
//   // Create and open a text file
//   std::ofstream myFile("adieu.txt");

//   // Write to the file
//   myFile << "Files can be tricky, but it is fun enough!";

//   // Close the file
//   myFile.close();
// }

int main(int argc, char** argv) {
	// un nom de fichier et deux strings, s1 et s2.
	if (argc != 4) {
		std::cout << "Provide a valid file name, string 1 and string 2." << std::endl;
		return (-42);
	}

	std::ifstream myfile(argv[1]);
	if (!myfile.is_open()) {
		std::cout << "Error opening file `" << argv[1] << "´." << std::endl;
		return (-42);
	}

	std::cout << "String to searched for: " << argv[2] << std::endl;
	std::cout << "String to replace it by: " << argv[3] << std::endl;

	myfile.close();

	return 0;
}