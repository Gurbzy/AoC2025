#ifndef FILES_H
#define FILES_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

inline std::vector<std::string> read_file(const char *filename) {
	std::ifstream infile(filename);

	if (!infile) {
		std::cerr << "failed to read " << filename << "\n";
		return {};
	}

	std::string line;
	int linect = 0;
	std::vector<std::string> input;

	while (getline(infile, line)) {
		linect++;
		input.push_back(line);
	}

	std::cout << "Read " << linect << " lines for  file " << filename << "\n";

	return input;
}

#endif
