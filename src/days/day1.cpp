#include "files.h"
#include <string>

void solution_1(const char *filename) {
	std::vector<std::string> input = read_file(filename);

	int start = 50;
	int password = 0;

	for (size_t i = 0; i < input.size(); i++) {
		std::string str_number = input[i].substr(1);
		int number = stoi(str_number);

		(input[i][0] == 'L') ? (start = (start - number + 100) % 100) : (start = (start + number + 100) % 100);

		if (start == 0) password++;
	}

	std::cout << "password is: " << password << "\n";
}
