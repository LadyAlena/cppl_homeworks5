#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <variant>

#include "ConvertData/ConvertData.hpp"
#include "DataProcessing/DataProcessing.hpp"

// написать функцию, определяющую тип данных - в in()

template<typename T>
T pow_square(T& data) { return data * data; }

template<typename T>
std::vector<T> pow_square(std::vector<T>& data) {
	std::transform(data.begin(), data.end(), data.begin(), [](T& value) { return value * value; });

	return data;
}

int main(int argc, char** argv) {

	try {
		DataProcessing<double> data_processing;

		auto result_input = data_processing.in();

		if (std::holds_alternative<double>(result_input)) {
			auto result = std::get<double>(result_input);

			data_processing.out(pow_square(result));
		}
		else if (std::holds_alternative<std::vector<double>>(result_input)) {
			auto& result = std::get<std::vector<double>>(result_input);

			data_processing.out(pow_square(result));
		}
	}
	catch (std::invalid_argument) { std::cout << "Некорректный ввод! Повторите попытку" << std::endl; }
	catch (std::out_of_range) { std::cout << "Введено слишком большое число! Повторите попытку" << std::endl; }
	catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
	catch (...) { std::cout << "Произошла неизвестная ошибка! Повторите попытку" << std::endl; }

	return 0;
}