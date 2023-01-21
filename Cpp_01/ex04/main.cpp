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
	std::string find = argv[2];
	std::string replace = argv[3];

	std::string outputFileName(argv[1]);
	outputFileName += ".replace";

	std::ofstream outputFile(outputFileName.c_str());

	if (find.empty()){
		std::cout << "sed: -e expression #1, char 0: no previous regular expression" << std::endl;
		return (-42);
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "Error opening file `" << argv[1] << "´." << std::endl;
		return (-42);
	}

	while(inputFile.good()) {
		std::getline(inputFile, lineRead);
		std::size_t pos = -1;

		do {
			pos++;
			pos = lineRead.find(find, pos);
			if (pos != std::string::npos){
				std::string remainder = lineRead.substr(pos + find.size());
				lineRead.erase(pos);
				lineRead += replace;
				lineRead += remainder;
			}
		} while (pos != std::string::npos);

		outputFile << lineRead;
		if (lineRead[0])
			outputFile << "\n";
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
