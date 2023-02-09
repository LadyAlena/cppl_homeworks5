#pragma once

template<typename T>
struct row {
	row(const int size);
	row() {};

	void del();

	T& operator[](const int index);
	const T& operator[](const int index) const;

	T* row_{};
	int size_row{};
};

template<typename T>
row<T>::row(const int size) : size_row(size) {

	if (size_row <= 0) { throw std::out_of_range("The number of rows cannot be less than or equal to zero"); }

	row_ = new T[size_row]{};
}

template<typename T>
void row<T>::del() { delete[] row_; }

template<typename T>
T& row<T>::operator[](const int index) {

	if (index < 0 || index >= size_row) {
		throw std::out_of_range("The line number cannot exceed the length of the line or be less than zero");
	}

	return row_[index];
}

template<typename T>
const T& row<T>::operator[](const int index) const {
	if (index < 0 || index >= size_row) {
		throw std::out_of_range("The line number cannot exceed the length of the line or be less than zero");
	}

	return row_[index];
}