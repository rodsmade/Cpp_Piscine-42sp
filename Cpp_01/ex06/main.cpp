#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: must pass in one of the four severity levels (`DEBUG´, `INFO`, `WARNING´, `ERROR´) as a parameter." << std::endl;
		return (-42);
	}

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int select = -42;

	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			select = i;
	}

	Harl karen;
	switch (select)
	{
	case DEBUG:
		karen.complain("DEBUG");
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
		break;
	case INFO:
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
		break;
	case WARNING:
		karen.complain("WARNING");
		karen.complain("ERROR");
		break;
	case ERROR:
		karen.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}