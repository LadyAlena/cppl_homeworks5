#pragma once

#include <string>

namespace convert_data {

	template<typename U>
	U sto(std::string enter_str) {

		U check_exception{};

		std::string result_str{};
		std::string result_str_i{};

		for (auto ch : enter_str) {

			result_str_i = ch;

			if (ch == '+' && ch == enter_str.at(0)) {
				result_str_i = "";
			}
			else if (ch == '-' && ch == enter_str.at(0)) {
				result_str_i = "-";
			}
			else {
				check_exception = std::stoi(result_str_i);
			}

			result_str += result_str_i;
		}

		return std::stoi(result_str);
	}

	template<>
	double sto(std::string enter_str) {

		double check_exception{};
		std::string result_str{};
		std::string result_str_i{};

		for (auto ch : enter_str) {

			result_str_i = ch;

			if (ch == '.' || ch == ',') {
				result_str_i = ".";
			}
			else if (ch == '+' && ch == enter_str.at(0)) {
				result_str_i = "";
			}
			else if (ch == '-' && ch == enter_str.at(0)) {
				result_str_i = "-";
			}
			else {
				check_exception = std::stod(result_str_i);
			}

			result_str += result_str_i;
		}

		return std::stod(result_str);
	}

	template<>
	float sto(std::string enter_str) {

		float check_exception{};
		std::string result_str{};
		std::string result_str_i{};

		for (auto ch : enter_str) {

			result_str_i = ch;

			if (ch == '.' || ch == ',') {
				result_str_i = ".";
			}
			else if ((ch == '+' && ch == enter_str.at(0)) || ch == 'f') {
				result_str_i = "";
			}
			else if (ch == '-' && ch == enter_str.at(0)) {
				result_str_i = "-";
			}
			else {
				check_exception = std::stof(result_str_i);
			}

			result_str += result_str_i;
		}

		return std::stof(result_str);
	}
}