#pragma once
#include <iostream>
#include <stdexcept>

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
		data_ = new T[capacity_];
		begin_ = nullptr;
		end_ = nullptr;
	}
	~myVector() {
		size_ = 0;
		capacity_ = 0;
		delete[] data_;
		begin_ = nullptr;
		end_ = nullptr;
	}
	int size() const {
		return size_;
	}
	int capacity() const {
		return capacity_;
	}
	T* begin() const {
		return begin_;
	}
	T* end() const {
		return end_;
	}
	T& operator[] (int index) const noexcept {
		if (index < 0 || index >= size_) throw std::out_of_range("Out of range!");
		return this->data_[index];
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
				begin_ = &data_[0];
				end_ = &data_[size_];
				temp = nullptr;
			}
		}
	}

	void pop_back() {
		if (size_ == 0) return;
		size_ = size_-1;
		end_ = end_-1;
	}

	bool empty() const {
		if (begin_ == end_) return true;
		return false;
	}

	T& front() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *begin_;
	}

	T& back() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *(end_ - 1);
	}

	T& at(int index) const {
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Out of range!");
			wcerr << "Out of range!";
			std::terminate();
		}
		return data_[index];
	}

	void reserve(int num) {
		if (num <= capacity_) return;
		capacity_ = num;
		T* temp = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			temp[i] = data_[i];
		}
		delete[] data_;
		data_ = temp;
		begin_ = &data_[0];
		end_ = &data_[size_];
		temp = nullptr;
	}
};
