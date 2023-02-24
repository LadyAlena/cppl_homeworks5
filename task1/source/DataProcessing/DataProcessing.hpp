#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <variant>
#include <regex>
#include "ConvertData/ConvertData.hpp"

template<typename T>
class DataProcessing {
public:
	auto in() {

		std::cout << "[IN]: ";
		std::getline(std::cin, input);

		auto result = input_processing();

		return result;
	}
	void out(const T& data) {
		this->data = data;
		std::cout << "[OUT]: " << data << std::endl;
	}
	void out(const std::vector<T>& data) {
		vector_data = data;

		std::cout << "[OUT]: ";
		for (auto& el : vector_data) {
			if (output_flag) { std::cout << el << (el != vector_data.back() ? ", " : "\n"); }
			else { std::cout << el << (el != vector_data.back() ? " " : "\n"); }
		}
	}

private:
	T data{};
	std::vector<T> vector_data{};

	struct {
		std::string input{};
		bool output_flag{};;
	};

	std::variant<T, std::vector<T>> input_processing() {

		std::variant<T, std::vector<T>> result;

		bool are_there_commas_and_gaps = input.find(", ") != input.npos;
		bool are_there_gaps = input.find(' ') != input.npos;

		output_flag = are_there_commas_and_gaps;

		if (are_there_gaps) {

			std::string input_i{};

			input += ' ';

			if (are_there_commas_and_gaps) { input = std::regex_replace(input, std::regex(", "), " "); }

			for (char ch : input) {
				if (ch != ' ') {
					if (ch == ',') { ch = '.'; }
					input_i += ch;
				}
				else {
					vector_data.push_back(convert_data::sto<T>(input_i));
					input_i = "";
				}
			}

			result = vector_data;
		}
		else {
			data = convert_data::sto<T>(input);

			result = data;
		}

		return result;
	}
};