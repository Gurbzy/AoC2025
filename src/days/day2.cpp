#include "day2.h"
#include "files.h"

static std::vector<std::pair<std::string, std::string>> parse_file(const char *filename) {
    std::vector<std::string> input = read_file(filename);

    size_t start = 0; size_t pos_end;
    std::string delimiter = ",";
    std::string num_delim = "-";
    std::string token;

    std::vector<std::pair<std::string, std::string>> pairs;

    for (size_t i = 0; i < input.size(); i++) {
	   while ((pos_end = input[i].find(delimiter, start)) != std::string::npos) {
		  token = input[i].substr(start, pos_end - start);
		  start += token.length() + 1;
		  
		  std::string num1, num2;
		  size_t tstart = 0;
		  size_t tend = token.find(num_delim, tstart);

		  num1 = token.substr(tstart, tend);
		  num2 = token.substr(tend + 1);

		  auto p = std::make_pair(num1, num2);
		  pairs.push_back(p);
	   }
    }

    return pairs;
}

static long check_1(long number) {
    std::string str = std::to_string(number);
    int n = str.length();

    for (size_t i = 1; i < str.length(); i++) {
	   if (n % i != 0) continue;

	   std::string pattern = str.substr(0, i);
	 
	   std::string built = pattern + pattern;

	   if (built == str) {
		  return stol(built);
	   }
    }

    return 0;
}

static long check_2(long number) {
    std::string str = std::to_string(number);
    int n = str.length();

    for (size_t i = 1; i < str.length(); i++) {
	   if (n % i != 0) continue;

	   std::string pattern = str.substr(0, i);
	 
	   std::string built;
	   while (built.length() != str.length()) {
		 built += pattern; 
	   }

	   if (built == str) {
		  return stol(built);
	   }
    }

    return 0;
}

void solution_2_1(const char *filename) {
    std::vector<std::pair<std::string , std::string>> ranges = parse_file(filename);
    long answer = 0;

    for (size_t i = 0; i < ranges.size(); i++) {
	   long f = stol(ranges[i].first);
	   long l = stol(ranges[i].second);

	   for (long range = f; range <= l; range++) {
		  long res = check_1(range);
		  answer += res;
	   }
    }

    std::cout << "sum of every pattern is " << answer << "\n";
}

void solution_2_2(const char *filename) {
    std::vector<std::pair<std::string , std::string>> ranges = parse_file(filename);
    long answer = 0;

    for (size_t i = 0; i < ranges.size(); i++) {
	   long f = stol(ranges[i].first);
	   long l = stol(ranges[i].second);

	   for (long range = f; range <= l; range++) {
		  long res = check_2(range);
		  answer += res;
	   }
    }

    std::cout << "sum of every pattern is " << answer << "\n";
}
