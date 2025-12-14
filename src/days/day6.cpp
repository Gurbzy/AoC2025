#include "files.h"
#include "day6.h"
#include <sstream>

typedef enum Operator {
	E_NONE,
	E_ADD,
	E_MULT,
} Operator;

typedef struct exprinfo {
	std::vector<std::string> operands;
	Operator op;
} exprinfo;

static std::vector<exprinfo> parsed(const char *filename) {
	std::vector<std::string> input = read_file(filename);

	std::vector<exprinfo> columns;

	for (size_t i = 0; i < input.size(); i++) {			
		std::istringstream ws(input[i]);
		std::string token;
		size_t count = 0;

		while (ws >> token) {
			if (count >= columns.size()) {
				columns.emplace_back();
			}
			if (token == "+") {
				columns[count].op = E_ADD;
			}
			else if (token == "*") {
				columns[count].op = E_MULT;
			}
			else {
				columns[count].operands.push_back(token);
			}
			count++;
		}
	}

	return columns;
}

static long perform_op(long rhs, long lhs, Operator o) {
	switch (o) {
		case E_NONE: return 0; break;
		case E_ADD:  return (lhs) + (rhs);
		case E_MULT: return (lhs) * (rhs);
	}
	return 0;
}

static std::string str_op(Operator o) {
	switch (o) {
		case E_NONE: return "E_NONE";
		case E_ADD:  return "E_ADD"; 
		case E_MULT: return "E_MULT"; 
	}
	return "TERRIBLE ERROR";
}

static void print_exprs(std::vector<exprinfo> &l) {
	for (size_t i = 0; i < l.size(); i++) {
		std::cout << str_op(l[i].op) << ":  ";
		for (size_t j = 0; j < l[i].operands.size(); j++) {
			std::cout << l[i].operands[j] << " ";
		}
		std::cout << "\n";
	}
}

void solution_6_1(const char* filename) {
	std::vector<exprinfo> input = parsed(filename);	

	long answer = 0;
	for (size_t i = 0; i < input.size(); i++) {
		long add_start = 0;
		long mul_start = 1;
		for (size_t j = 0; j < input[i].operands.size(); j++) {
			Operator o = input[i].op;
			switch (o) {
				case E_ADD:  add_start = perform_op(add_start, stol(input[i].operands[j]), o); break;
				case E_MULT: mul_start = perform_op(mul_start, stol(input[i].operands[j]), o); break;
			}
		}
		(add_start == 0) ? answer += mul_start : answer += add_start;
	}

	std::cout << "answer is: " << answer << "\n";
}
