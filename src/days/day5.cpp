#include "day5.h"
#include "files.h"
#include <algorithm>

static void parse_file(std::vector<std::pair<long, long>> &ranges, std::vector<long> &input_list, const char *filename) {
    std::vector<std::string> input = read_file(filename);
    size_t start = 0; size_t range_end;

    for (size_t i = 0; i < input.size(); i++) {
	   range_end = input[i].find("-", start);

	   if (range_end == std::string::npos) {
		  input_list.push_back(stol(input[i]));
		  continue;
	   }

	   std::string num1, num2;
	   num1 = input[i].substr(start, range_end - start);
	   num2 = input[i].substr(range_end + 1);

	   auto p = std::make_pair(stol(num1), stol(num2));
	   ranges.push_back(p);
    }
}

static bool inRange(std::pair<long, long> p, long n) {
    return p.first <= n && n <= p.second;
}

static bool exhaust_pairs(std::vector<std::pair<long, long>> &ranges, long n) {
    bool result;
    for (size_t i = 0; i < ranges.size(); i++) {
	   if ((result = inRange(ranges[i], n))) return result;
    }
    return false;
}

void solution_5_1(const char *filename) {
    std::vector<std::pair<long, long>> ranges;
    std::vector<long> input_list;
    long answer = 0;

    parse_file(ranges, input_list, filename);

    for (size_t i = 0; i < input_list.size(); i++) {
	   bool check = exhaust_pairs(ranges, input_list[i]);
	   if (check) answer++;
    }

    std::cout << "total fresh ingredients: " << answer << "\n";
}

void solution_5_2(const char *filename) {
    std::vector<std::pair<long, long>> ranges;
    std::vector<long> input_list;
    long answer = 0;

    parse_file(ranges, input_list, filename);

    std::sort(ranges.begin(), ranges.end(), [](const auto &a, const auto &b) {
		  return a.first < b.first;
    });

    size_t merged = 0;
    for (size_t i = 1; i < ranges.size(); i++) {
	   if (ranges[merged].second >= ranges[i].first) {
		  ranges[merged].second = std::max(ranges[merged].second, ranges[i].second); 
	   }
	   else {
		  merged++;
		  ranges[merged] = ranges[i];
	   }
    }    
    ranges.resize(merged + 1);
        
    for (size_t i = 0; i < ranges.size(); i++) {
	   answer += ranges[i].second - ranges[i].first + 1;
    }
    std::cout << "total fresh ingredients are: " << answer << "\n";
}
