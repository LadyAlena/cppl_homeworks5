#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "source/InOutData/InOutData.hpp"

bool checking_div_by3(std::string number) {

	int sum{};
	bool result{};

	for (auto& ch : number) {
		if (ch == '.' || ch == ',') { continue; }

		sum += (ch - '0');
	}

	if (sum % 3 == 0) { result = true; }
	else { result = false; }

	return result;
}

template<typename T>
class Sum {
public:
	Sum(const std::vector<T>& v) : v(std::move(v)) {};
	
	T operator()() {
	
		auto sum = std::accumulate(std::begin(v), std::end(v), 0,
			[](T current_sum, T& val) {

				if (checking_div_by3(std::to_string(val))) { current_sum += val; }

				return current_sum;
			}
		);

		return sum;
	};

private:
	std::vector<T> v;
};

template<typename T>
class Count {
public:
	Count(const std::vector<T>& v) : v(std::move(v)) {};

	int operator()() {

		auto count = std::accumulate(std::begin(v), std::end(v), 0,
			[](int current_count, T& val) {

				if (checking_div_by3(std::to_string(val))) { current_count++; }

				return current_count;
			}
		);

		return count;
	};

private:
	std::vector<T> v;
};

int main(int argc, char** argv) {

	try {
		std::vector<int> v = {};

		InOutData<decltype(v)::value_type> in_out_data;

		v = in_out_data.in();

		Sum<decltype(v)::value_type> get_sum(v);
		Count<decltype(v)::value_type> get_count(v);

		auto sum = get_sum();
		auto count = get_count();

		std::cout << "[OUT]: get_sum() = " << sum << std::endl;
		std::cout << "[OUT]: get_count() = " << count << std::endl;
	}
	catch (std::invalid_argument) { std::cout << "Некорректный ввод! Повторите попытку" << std::endl; }
	catch (std::out_of_range) { std::cout << "Введено слишком большое число! Повторите попытку" << std::endl; }
	catch (std::exception& ex) { std::cout << ex.what() << std::endl; }
	catch (...) { std::cout << "Произошла неизвестная ошибка! Повторите попытку" << std::endl; }

	return 0;
}