#include <iostream>
#include <exception>

#include "../task2/source/table/table.hpp"

int main(int argc, char** argv) {

	try {
		table<int> t(2, 3);

		t[1][0] = 3;

		std::cout << t[1][0] << std::endl;

		auto& [rows, colomns] = t.Size();

		std::cout << "Number of rows is " << rows << std::endl;
		std::cout << "Number of colomns is " << colomns << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Uknown error" << std::endl;
	}

	return 0;
}