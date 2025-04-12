#pragma once

template<typename T>
class Vector {
private:
	int size_;
	int capacity_;
	T* data_;
	T* begin, end;
public:
	Vector() {
		size_ = 10;
		capacity_ = 10;
		data_ = new T[size_];
		begin = end = nullptr;
	}
	~Vector() {
		size_ = 0;
		capacity_ = 0;
		delete[] data_;
		delete begin;
		delete end;
	}
};
