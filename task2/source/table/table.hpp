#pragma once

#include "../source/table/row/row.hpp"

template<typename T>
class table {
public:
	table(const int rows, const int colomns);
	table(const table& r) = delete;
	~table();
	table& operator=(const table& r) = delete;
	row<T>& operator[](const int index);
	const row<T>& operator[](const int index) const;

private:
	row<T>* tabel_{};

	struct size_tabel {
		int rows{};
		int colomns{};
	}size_tabel_;

public:
	const size_tabel& Size() const { return size_tabel_; };
	
};

template<typename T>
table<T>::table(const int rows, const int colomns) {

	if (rows <= 0 || colomns <= 0) { throw std::out_of_range("The number of rows or columns cannot be less than or equal to zero"); }

	size_tabel_.rows = rows;
	size_tabel_.colomns = colomns;

	tabel_ = new row<T>[rows];

	for (int i = 0; i < rows; ++i) {
		tabel_[i] = row<T>(colomns);
	}
}

template<typename T>
table<T>::~table() {
	for (int i = 0; i < size_tabel_.rows; ++i) {
		tabel_[i].del();
	}

	delete[] tabel_;
}

template<typename T>
row<T>& table<T>::operator[](const int index) {

	if (index < 0 || index >= size_tabel_.rows) {
		throw std::out_of_range("The line number cannot exceed the length of the line or be less than zero");
	}

	return tabel_[index];
}

template<typename T>
const row<T>& table<T>::operator[](const int index) const {
	if (index < 0 || index >= size_tabel_.rows) {
		throw std::out_of_range("The line number cannot exceed the length of the line or be less than zero");
	}

	return tabel_[index];
}