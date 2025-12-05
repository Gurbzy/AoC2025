#include "files.h"
#include "day3.h"

void solution_3_1(const char *filename) {
    std::vector<std::string> input = read_file(filename);
    long answer = 0;

    for (size_t i = 0; i < input.size(); i++) {
	   std::string biggest;
	   std::pair<char, int> first_idx = {'0', 0};
	   char second = '0';

	   for (size_t c = 0; c < input[i].length() - 1; c++) {
		 if (input[i][c] > first_idx.first) {
			first_idx.first = input[i][c];
			first_idx.second = c; // index we found it
		 }
	   }

	   for (size_t rest = first_idx.second + 1; rest < input[i].length(); rest++) {
		  if (input[i][rest] > second) {
			 second = input[i][rest];
		  }
	   }


	   biggest = std::string(1, first_idx.first) + std::string(1, second);
	   answer += stol(biggest);
    }

    std::cout << "sum of all volts is " << answer << "\n";
}


void solution_3_2(const char *filename) {
    std::vector<std::string> input = read_file(filename);
    long answer = 0;

    for (size_t i = 0; i < input.size(); i++) {
	   int k = 12;
	   std::string biggest;
	   std::pair<char, size_t> num_idx = {'0', 0};

	   while (k > 0) {
		  for (size_t c = num_idx.second; c <= input[i].length() - k; c++) {
			 if (input[i][c] > num_idx.first) {
				num_idx.first = input[i][c];
				num_idx.second = c + 1; // index we start next loop at
			 }
		  }
		  biggest += std::string(1, num_idx.first);
		  num_idx.first = '0';
		  k--;
	   }
	   answer += stol(biggest);
    }

    std::cout << "total jolts is : " << answer << "\n";
}
