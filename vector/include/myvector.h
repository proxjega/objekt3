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
	/** Basic Constructor
	* @brief Creates an empty vector with default capacity of 10
	*/
	myVector() { // basic constructor
		size_ = 0;
		capacity_ = 10;
		data_ = new T[capacity_];
		begin_ = nullptr;
		end_ = nullptr;
	}
	/** Fill constructor 
	* @brief Creates a vector with given size and fills it with given value
	* @param num - size of the vector
	* @param val - value to fill the vector with
	*/
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
	/** Range constructor
	* @brief Creates a vector with values from given range
	* @param begin - pointer to the beginning of the range
	* @param end - pointer to the end of the range
	*/
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
	/** Copy constructor
	* @brief Creates a vector with values from given vector. Values in original vector are not moved
	* @param other - vector to copy from
	*/
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
	/** Move constructor
	* @brief Creates a vector with values from given vector and "moves" the values from it
	* @param other - vector to move from
	*/
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
	/** Initializer list constructor
	* @brief Creates a vector with values from given initializer list
	* @param list - initializer list to copy from
	*/
	myVector(std::initializer_list<T> list) { //initalizer list constructor
		size_ = static_cast<int>(list.size());
		capacity_ = size_;
		data_ = new T[capacity_];
		std::copy(list.begin(), list.end(), data_);
		begin_ = &data_[0];
		end_ = &data_[size_];
	}
	/** Operator = with initalizer list
	* @brief Assigns values from given initializer list to the vector
	* @param list - initializer list to copy from
	* @returns the vector
	*/
	myVector operator=(std::initializer_list<T> list) { // operator = with initalizer list
		this->~myVector();
		size_ = static_cast<int>(list.size());
		capacity_ = size_;
		data_ = new T[capacity_];
		std::copy(list.begin(), list.end(), data_);
		begin_ = &data_[0];
		end_ = &data_[size_];
		return *this;
	}
	/** Copy assignment operator
	* @brief Assigns values from given vector to the vector. Values in original vector are not moved
	* @param other - vector to copy from
	* @returns the vector
	* @see myVector(const myVector& other)
	*/
	myVector& operator= (const myVector& other) { // copy assignment
		if (this == &other) return *this;
		this->~myVector();
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
		return *this;
	}
	/** Move assignment operator
	* @brief Assigns values from given vector to the vector and "moves" the values from it
	* @param other - vector to move from
	* @returns the vector
	* @see myVector(myVector&& other)
	*/
	myVector& operator= (myVector&& other) { // move assignment
		if (this == &other) return *this;
		this->~myVector();
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
		return *this;
	}
	/** Destructor
	* @brief Calls the destructor for every element in vector and frees the memory
	*/
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
	/** Size
	* @brief Returns the size of the vector
	* @return Size of vector (integer)
	*/
	int size() const {
		return size_;
	}
	/** Capacity
	* @brief Returns the capacity of the vector
	* @return Capacity of vector (integer)
	*/
	int capacity() const {
		return capacity_;
	}
	/** Begin
	* @brief Returns the pointer to the beginning of the vector
	* @return Pointer to the beginning of the vector (template typename T*)
	*/
	T* begin() {
		return begin_;
	}
	/** Const begin
	* @brief Returns the pointer to the beginning of the vector, but as const
	* @return Pointer to the beginning of the vector (template typename T*)
	*/
	T* cbegin() const {
		return begin_;
	}
	/** End
	* @brief Returns the pointer to element past the end of the vector
	* @return Pointer to element past the end of the vector (template typename T*)
	*/
	T* end() {
		return end_;
	}
	/** Const end
	* @brief Returns the pointer to element past the end of the vector, but as const
	* @return Pointer to element past the end of the vector (template typename T*)
	*/
	T* cend() const {
		return end_;
	}
	/** Front
	* @brief Returns the first element of the vector
	* @return First element of the vector (template typename T)
	*/
	T& front() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *begin_;
	}
	/** Back
	* @brief Returns the last element of the vector
	* @return Last element of the vector (template typename T)
	*/
	T& back() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *(end_ - 1);
	}
	/** Operator []
	* @brief Returns the element at given index
	* @param index - index of the element
	* @return Element at given index (template typename T)
	*/
	T& operator[] (int index) const noexcept {
		//if (index < 0 || index >= size_) throw std::out_of_range("Out of range!");
		return this->data_[index];
	}
	/** At
	* @brief Returns the element at given index (with bounds checking)
	* @param index - index of the element
	* @return Element at given index (template typename T)
	*/
	T& at(int index) const {
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Out of range!");
			std::wcerr << "Out of range!";
			std::terminate();
		}
		return data_[index];
	}
	/** Push back
	* @brief Adds an element to the end of the vector. If the vector is full, it doubles the capacity
	* @param value - value to add
	*/
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
	/** Pop back
	* @brief Removes the last element of the vector
	*/
	void pop_back() {
		if (size_ == 0) return;
		~data_[size_ - 1];
		size_ = size_-1;
		end_ = end_-1;
	}
	/** Empty
	* @brief Checks if the vector is empty
	* @return True if the vector is empty, false otherwise (bool)
	*/
	bool empty() const {
		if (begin_ == end_) return true;
		return false;
	}
	/** Reserve
	* @brief Reserves memory for the vector. If the given number is smaller than the current capacity, it does nothing
	* @param num - number of elements to reserve memory for
	*/
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
	/** Shrink to fit
	* @brief Shrinks the vector to fit the current size. If the capacity is equal to the size, it does nothing
	*/
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
	/** Clear
	* @brief Clears the vector. Calls the destructor for every element in vector. Frees the old memory, but the capacity remains the same.
	*/
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
	/** Output
	* @brief Outputs the vector to a string (for testing purposes)
	* @return String with the vector values (std::wstring)
	*/
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
	/** Equal operator
	* @brief Compares two vectors. If the sizes are different, it returns false. If the sizes are the same, it compares the elements.
	* @return True if the vectors are equal, false otherwise (bool)
	*/
	bool operator==(const myVector& second) const {
		if (size_ != second.size_) return false;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return false;
		}
		return true;
	}
	/** Not equal operator
	* @brief Compares two vectors. If the sizes are different, it returns true. If the sizes are the same, it compares the elements.
	* @param second - vector to compare with
	* @return True if the vectors are not equal, false otherwise (bool)
	*/
	bool operator!=(const myVector& second) const {
		if (size_ != second.size_) return true;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return true;
		}
		return false;
	}
};
