#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
	// un nom de fichier et deux strings, s1 et s2.
	if (argc != 4) {
		std::cout << "Provide a valid file name, string 1 and string 2." << std::endl;
		return (-42);
	}

	std::string lineRead;

	std::string outputFileName(argv[1]);
	outputFileName += ".replace";

	std::ofstream outputFile(outputFileName.c_str());

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "Error opening file `" << argv[1] << "´." << std::endl;
		return (-42);
	}

	std::cout << "String to searched for: " << argv[2] << std::endl;
	std::cout << "String to replace it by: " << argv[3] << std::endl;

	while(inputFile.good()) {
		std::getline(inputFile, lineRead);
		std::size_t pos = 0;

		while (true) {
			pos = lineRead.find("fl", pos);
			std::cout << pos << std::endl;
			if (pos != std::string::npos)
				pos++;
			else
				break;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
