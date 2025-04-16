#pragma once
#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>
#include <algorithm>
#include <initializer_list>

template<typename T>
class myVector {
private:
	int size_;
	int capacity_;
	T* data_;
	T* begin_;
	T* end_;
public:
	myVector() { // basic constructor
		size_ = 0;
		capacity_ = 10;
		data_ = new T[capacity_];
		begin_ = nullptr;
		end_ = nullptr;
	}

	myVector(int num, T val) { // fill constructor
		size_ = num;
		capacity_ = num;
		data_ = new T[capacity_];
		for (int i = 0; i < num; i++) {
			data_[i] = val;
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}

	myVector(T* begin, T* end) { //range constructor
		size_ = end - begin;
		capacity_ = size_;
		data_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = *(begin + i);
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}

	myVector(const myVector& other) { // copy constructor
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}

	myVector(myVector&& other) { //move constructor
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = other.data_;
		begin_ = &data_[0];
		end_ = &data_[size_]; 
		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
		other.begin_ = nullptr;
		other.end_ = nullptr;
	}

	myVector(std::initializer_list<T> list) { //initalizer list constructor
		size_ = static_cast<int>(list.size());
		capacity_ = size_;
		data_ = new T[capacity_];
		std::copy(list.begin(), list.end(), data_);
		begin_ = &data_[0];
		end_ = &data_[size_];
	}

	myVector& operator= (const myVector& other) { // copy assignment
		if (this == &other) return *this;
		delete[] data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}

	myVector& operator= (myVector&& other) { // move assignment
		if (this == &other) return *this;
		delete [] data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = other.data_;
		begin_ = &data_[0];
		end_ = &data_[size_];
		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
		other.end_ = nullptr;
		other.begin_ = nullptr;
	}

	~myVector() {
		for (T* it = data_; it != data_ + size_; it++) {
			it->~T();
		}
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

	T* begin() {
		return begin_;
	}

	T* cbegin() const {
		return begin_;
	}

	T* end() {
		return end_;
	}

	T* cend() const {
		return end_;
	}

	T& front() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *begin_;
	}

	T& back() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *(end_ - 1);
	}
	
	T& operator[] (int index) const noexcept {
		//if (index < 0 || index >= size_) throw std::out_of_range("Out of range!");
		return this->data_[index];
	}

	T& at(int index) const {
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Out of range!");
			std::wcerr << "Out of range!";
			std::terminate();
		}
		return data_[index];
	}
	
	void push_back(const T& value) {
		if (capacity_ == 0) {
			capacity_ = 10;
			data_ = new T[capacity_];
		}
		if (size_ == 0) {
			data_[0] = value;
			begin_ = &data_[0];
			end_ = &data_[0] + 1;
			size_ = 1;
		}
		else {
			if (size_ >= capacity_) {
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
			data_[size_] = value;
			end_ = &data_[size_] + 1;
			size_++;
			
		}
	}

	void pop_back() {
		if (size_ == 0) return;
		~data_[size_ - 1];
		size_ = size_-1;
		end_ = end_-1;
	}

	bool empty() const {
		if (begin_ == end_) return true;
		return false;
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

	void shrink_to_fit() {
		if (capacity_ <= size_) return;
		capacity_ = size_;
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

    void clear() {
       if (size_ == 0) return;
	   for (T* it = data_; it != data_ + size_; it++) {
		   it->~T();
	   }
	   delete[] data_;
	   data_ = new T[capacity_];
       size_ = 0;
       end_ = begin_;
    }

	std::wstring output() const {
		std::wstringstream out;
		out << size_;
		if (size_ != 0) {
			out << *begin_ << *(end_ - 1);
			for (int i = 0; i < size_; i++) {
				out << data_[i];
			}
		}
		std::wstring str;
		str = out.str();
		return str;
	}	

	bool operator==(const myVector& second) const {
		if (size_ != second.size_) return false;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return false;
		}
		return true;
	}

	bool operator!=(const myVector& second) const {
		if (size_ != second.size_) return true;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return true;
		}
		return false;
	}
};
