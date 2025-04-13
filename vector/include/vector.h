#pragma once

template<typename T>
class Vector {
private:
	int size_;
	int capacity_;
	T* data_;
	T* begin_, end_;
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
		delete begin_;
		delete end_;
	}
	void push_back(T value) {
		if (size_ = 0) {
			data_[0] = value;
			begin_ = &data_[0];
			end_ = &data_[0] + 1;
			size_ = 1;
		}
		else {
			data_[size_] = value;
			end_ = &data_[size_] + 1;
		}
	}
};
