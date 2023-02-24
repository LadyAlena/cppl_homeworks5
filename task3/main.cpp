#include <iostream>
#include <string>
#include <vector>

template <typename T>
class CounterOfNumbersDivisibleBy3 {
public:
	void operator()(T number) {
		if(checking_div_by3(std::to_string(number))) {
			sum += number;
			count++;
		}
	};

	T get_sum() { return sum; }
	unsigned int get_count() { return count; }

private:
	T sum{};
	unsigned int count{};

	bool checking_div_by3(std::string number) {

		int sum_numbers{};
		bool result{};

		for (auto& ch : number) {
			if (ch == '.' || ch == ',') { continue; }

			sum_numbers += (ch - '0');
		}

		if (sum_numbers % 3 == 0) { result = true; }
		else { result = false; }

		return result;
	}
};

int main(int argc, char** argv) {

	CounterOfNumbersDivisibleBy3<int> is_it_div_by_3;

	std::vector<int> v{ 4, 1, 3, 6, 25, 54 };

	std::cout << "[IN]: ";
	for (auto& el : v) { std::cout << el << (el != v.back() ? " " : "\n"); }

	for (auto& el : v) { is_it_div_by_3(el); }

	std::cout << "[OUT]: get_sum() = " << is_it_div_by_3.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << is_it_div_by_3.get_count() << std::endl;

	return 0;
}