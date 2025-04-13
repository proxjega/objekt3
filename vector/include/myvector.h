#pragma once
#include <iostream>

template<typename T>
class myVector {
private:
	int size_;
	int capacity_;
	T* data_;
	T* begin_;
	T* end_;
public:
	myVector() {
		size_ = 0;
		capacity_ = 10;
		data_ = new T[size_];
		begin_ = nullptr;
		end_ = nullptr;
	}
	~myVector() {
		size_ = 0;
		capacity_ = 0;
		delete[] data_;
		delete begin_;
		delete end_;
	}
	void push_back(T value) {
		if (size_ == 0) {
			data_[0] = value;
			begin_ = &data_[0];
			end_ = &data_[0] + 1;
			size_ = 1;
		}
		else {
			data_[size_] = value;
			end_ = &data_[size_] + 1;
			size_++;
			if (size_ == capacity_) {
				capacity_ = capacity_ * 2;
				T* temp = new T[capacity_];
				for (int i = 0; i < size_; i++) {
					temp[i] = data_[i];
				}
				delete[] data_;
				data_ = temp;
				temp = nullptr;
			}
		}
	}
	T& operator[] (int index) {
		return data_[index];
	}
};
