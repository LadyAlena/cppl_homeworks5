#pragma once

#include <iostream>
#include <vector>
#include <regex>

#include "ConvertData/ConvertData.hpp"

template<typename T>
class InOutData {
public:
	std::vector<T> in();
	void out();

private:
	std::vector<T> data{};
	bool output_flag{};
	std::vector<T> input_processing(std::string& input);
};

template<typename T>
std::vector<T> InOutData<T>::in() {

	std::string input{};

	std::cout << "[IN]: ";
	std::getline(std::cin, input);

	input_processing(input);

	return data;
}

template<typename T>
void InOutData<T>::out() {
	std::cout << "[OUT]: ";
	for (auto& el : data) {
		if (output_flag) { std::cout << el << (el != data.back() ? ", " : "\n"); }
		else { std::cout << el << (el != data.back() ? " " : "\n"); }
	}
}

template<typename T>
std::vector<T> InOutData<T>::input_processing(std::string& input) {

	bool are_there_commas_and_gaps = input.find(", ") != input.npos;
	output_flag = are_there_commas_and_gaps;

	std::string input_i{};

	input += ' ';

	if (are_there_commas_and_gaps) { input = std::regex_replace(input, std::regex(", "), " "); }

	for (char ch : input) {
		if (ch != ' ') {
			if (ch == ',') { ch = '.'; }
			input_i += ch;
		}
		else {
			data.push_back(convert_data::sto<T>(input_i));
			input_i = "";
		}
	}

	return data;
}