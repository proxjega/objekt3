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
	/**
	* @brief Creates an empty vector with default capacity of 10
	*/
	myVector() { // basic constructor
		size_ = 0;
		capacity_ = 10;
		data_ = new T[capacity_];
		begin_ = data_;
		end_ = data_;
	}
	/**
	* @brief Creates a vector with given size and fills it with given value \n
	* @param num - size of the vector \n
	* @param val - value to fill the vector with
	*/
	myVector(const int& num, const T& val) { // fill constructor
		size_ = num;
		capacity_ = num;
		data_ = new T[capacity_];
		for (int i = 0; i < num; i++) {
			data_[i] = val;
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}
	/**
	* @brief Creates a vector with values from given range \n
	* @param begin - pointer to the beginning of the range \n
	* @param end - pointer to the end of the range
	*/
	myVector(const T* begin, const T* end) { //range constructor
		size_ = end - begin;
		capacity_ = size_;
		data_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = *(begin + i);
		}
		begin_ = &data_[0];
		end_ = &data_[size_];
	}
	/**
	* @brief Creates a vector with values from given vector. Values in original vector are not moved \n
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
	/**
	* @brief Creates a vector with values from given vector and "moves" the values from it \n
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
	/**
	* @brief Creates a vector with values from given initializer list \n
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
	/**
	* @brief Assigns values from given initializer list to the vector \n
	* @param list - initializer list to copy from \n
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
	/**
	* @brief Assigns values from given vector to the vector. Values in original vector are not moved \n
	* @param other - vector to copy from \n
	* @returns the vector \n
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
	/**
	* @brief Assigns values from given vector to the vector and "moves" the values from it \n
	* @param other - vector to move from \n
	* @returns the vector \n
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
	/**
	* @brief Frees the memory and resets size_, capacity_, begin_ and end_
	*/
	~myVector() {
		size_ = 0;
		capacity_ = 0; 
		delete[] data_;
		begin_ = nullptr;
		end_ = nullptr;
	}
	/**
	* @brief Returns the size of the vector \n
	* @return Size of vector (integer)
	*/
	int size() const {
		return size_;
	}
	/**
	* @brief Returns the capacity of the vector \n
	* @return Capacity of vector (integer)
	*/
	int capacity() const {
		return capacity_;
	}
	/**
	* @brief Returns the pointer to the beginning of the vector \n
	* @return Pointer to the beginning of the vector (template typename T*)
	*/
	T* begin() {
		return begin_;
	}
	/**
	* @brief Returns the pointer to the beginning of the vector, but as const \n
	* @return Pointer to the beginning of the vector (template typename T*)
	*/
	T* cbegin() const {
		return begin_;
	}
	/**
	* @brief Returns the pointer to element past the end of the vector \n
	* @return Pointer to element past the end of the vector (template typename T*)
	*/
	T* end() {
		return end_;
	}
	/**
	* @brief Returns the pointer to element past the end of the vector, but as const \n
	* @return Pointer to element past the end of the vector (template typename T*)
	*/
	T* cend() const {
		return end_;
	}
	/**
	* @brief Returns the first element of the vector \n
	* @return First element of the vector (template typename T)
	*/
	T& front() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *begin_;
	}
	/**
	* @brief Returns the last element of the vector \n
	* @return Last element of the vector (template typename T)
	*/
	T& back() const {
		if (this->empty()) throw std::out_of_range("Vector is empty");
		return *(end_ - 1);
	}
	/**
	* @brief Returns the element at given index \n
	* @param index - index of the element \n
	* @return Element at given index (template typename T)
	*/
	T& operator[] (const int& index) const noexcept {
		//if (index < 0 || index >= size_) throw std::out_of_range("Out of range!");
		return this->data_[index];
	}
	/**
	* @brief Returns the element at given index (with bounds checking) \n
	* @param index - index of the element \n
	* @return Element at given index (template typename T)
	*/
	T& at(const int& index) const {
		if (index < 0 || index >= size_) {
			throw std::out_of_range("Out of range!");
			std::wcerr << "Out of range!";
			std::terminate();
		}
		return data_[index];
	}
	/**
	* @brief Adds an element to the end of the vector. If the vector is full, it doubles the capacity. \n
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
	/**
	* @brief Removes the last element of the vector
	*/
	void pop_back() {
		if (size_ == 0) return;
		~data_[size_ - 1];
		size_ = size_-1;
		end_ = end_-1;
	}
	/**
	* @brief Checks if the vector is empty \n
	* @return True if the vector is empty, false otherwise (bool)
	*/
	bool empty() const {
		if (begin_ == end_) return true;
		return false;
	}
	/**
	* @brief Reserves memory for the vector. If the given number is smaller than the current capacity, it does nothing \n
	* @param num - number of elements to reserve memory for
	*/
	void reserve(const int& num) {
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
	/**
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
	/**
	* @brief Clears the vector. Frees the old memory, but the capacity remains the same.
	*/
    void clear() {
       if (size_ == 0) return;
	   delete[] data_;
	   data_ = new T[capacity_];
       size_ = 0;
	   begin_ = data_;
       end_ = begin_;
    }
	/**
	* @brief Outputs the vector to a string (for testing purposes) \n
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
	/**
	* @brief Compares two vectors. If the sizes are different, it returns false. If the sizes are the same, it compares the elements. \n
	* @return True if the vectors are equal, false otherwise (bool)
	*/
	bool operator==(const myVector& second) const {
		if (size_ != second.size_) return false;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return false;
		}
		return true;
	}
	/**
	* @brief Compares two vectors. If the sizes are different, it returns true. If the sizes are the same, it compares the elements. \n
	* @param second - vector to compare with \n
	* @return True if the vectors are not equal, false otherwise (bool)
	*/
	bool operator!=(const myVector& second) const {
		if (size_ != second.size_) return true;
		for (int i = 0; i < size_; i++) {
			if (data_[i] != second.data_[i]) return true;
		}
		return false;
	}
	/**
	* @brief Replaces the elements with num copies of val value.\n
	* @param num - number of elements to replace \n
	* @param val - value to replace with
	*/
	void assign(const int& num, const T& val) {
		if (num <= capacity_) {
			if (num > size_) {
				size_ = num;
				end_ = &data_[size_];
			}
			for (int i = 0; i < num; i++) {
				~data_[i];
				data_[i] = val;
			}
		}
		else {
			this->~myVector();
			capacity_ = num;
			size_ = num;
			data_ = new T[capacity_];
			for (int i = 0; i < size_; i++) {
				data_[i] = val;
			}
			begin_ = &data_[0];
			end_ = &data_[size_];
		}
	}
	
	/**
	* @brief Replaces the elements with elements from range from start to end \n
	* @param start - pointer to a start of a range \n
	* @param end - pointer to an end of a range
	*/
	void assign(const T* start, const T* end) {
		int num = end - start;
		if (num <= capacity_) {
			if (num > size_) {
				size_ = num;
				end_ = &data_[size_];
			}
			for (int i = 0; i < num; i++) {
				~data_[i];
				data_[i] = *(start+i);
			}
		}
		else {
			this->~myVector();
			capacity_ = num;
			size_ = num;
			data_ = new T[capacity_];
			for (int i = 0; i < size_; i++) {
				data_[i] = *(start + i);
			}
			begin_ = &data_[0];
			end_ = &data_[size_];
		}
	}
	/**
	* @brief Returns pointer to the underlying array
	* @return Pointer to start of the data_ array
	*/
	T* data() const {
		return &data_[0];
	}
	/**
	* @brief Inserts an copy of element val into place before position pos\n
	* @param pos - pointer to position\n
	* @param val - value to insert
	*/
	void insert(const T* pos,  const T& val) {
		int index = pos - begin_;
		if (size_ + 1 <= capacity_) {
			for (auto it = end_; it != pos; it--) {
				*it = *(it - 1);
			}
			data_[index] = val;
			size_++;
			end_ = &data_[size_];
		}
		else {
			capacity_ = capacity_ * 2;
			T* temp = new T[capacity_];
			for (int i = 0; i != index; i++) {
				temp[i] = data_[i];
			}
			temp[index] = val;
			for (int i = index; i < size_; i++) {
				temp[i+1] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			begin_ = data_;
			size_++;
			end_ = &data_[size_];
		}
	}
	/**
	* @brief Inserts a num copies of element val into place before position pos\n
	* @param pos - pointer to position\n
	* @param num - number of copies to insert\n
	* @param val - value to insert
	*/
	void insert(const T* pos, const int num, const T& val) {
		int index = pos - begin_;
		if (size_ + num <= capacity_) {
			for (auto it = end_ + num - 1; it != pos; it--) {
				*it = *(it - num);
			}
			for (int i = num; i > 0; i--) {
				data_[index + i - 1] = val;
			}
			size_ = size_ + num;
			end_ = &data_[size_];
		}
		else {
			capacity_ = capacity_ + num;
			T* temp = new T[capacity_];
			for (int i = 0; i != index; i++) {
				temp[i] = data_[i];
			}
			for (int i = index; i < index + num; i++) {
				temp[i] = val;
			}
			for (int i = index; i < size_; i++) {
				temp[i + num] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			begin_ = data_;
			size_ = size_ + num;
			end_ = &data_[size_];
		}
	}
	/**
	* @brief Inserts copies from a range from start to end into place before pos\n
	* @param pos - pointer to position\n
	* @param start - pointer to a start of a range\n
	* @param end - pointer to an end of a range
	*/
	void insert(const T* pos, const T* start, const T* end) {
		int index = pos - begin_;
		int num = end - start;
		if (size_ + num <= capacity_) {
			for (auto it = end_ + num - 1; it != pos; it--) {
				*it = *(it - num);
			}
			for (int i = num; i > 0; i--) {
				data_[index + i - 1] = *(start + i);
			}
			size_ = size_ + num;
			end_ = &data_[size_];
		}
		else {
			capacity_ = capacity_ + num;
			T* temp = new T[capacity_];
			for (int i = 0; i != index; i++) {
				temp[i] = data_[i];
			}
			for (int i = index; i < index + num; i++) {
				temp[i] = *(start + i - index);
			}
			for (int i = index; i < size_; i++) {
				temp[i + num] = data_[i];
			}
			delete[] data_;
			data_ = temp;
			begin_ = data_;
			size_ = size_ + num;
			end_ = &data_[size_];
		}
	}
	/**
	* @brief Erases element at pos\n
	* @param pos - pointer to a position
	*/
	void erase(const T* pos) {
		if (size_ == 0) return;
		int index = pos - begin_;
		~data_[index];
		for (int i = index; i < size_ - 1; i++) {
			data_[i] = data_[i + 1];
		}
		size_--;
		end_ = &data_[size_];
	}
	/**
	* @brief Erases elements in range from start to end\n
	* @param start - start of a range
	* @param end - end of a range
	*/
	void erase(const T* start, const T* end) {
		if (size_ == 0) return;
		int indexstart = start - begin_;
		int indexend = end - begin_;
		for (int i = indexstart; i < indexend; i++) {
			~data_[i];
		}
		for (int i = indexstart; i < size_ - 1; i++) {
			data_[i] = data_[i + end - start];
		}
		size_ = size_ - (end - start);
		end_ = &data_[size_];
	}
	/**
	* @brief Resizes the vector to a size\n
	* @param size - size to resize to
	*/
	void resize(const int& size) {
		if (size == size_) return;
		else if (size < size_) {
			for (int i = size; i < size_; i++) {
				~T();
			}
			size_ = size;
			end_ = &data_[size_];
		}
		else if (size > size_) {
			if (size <= capacity_) {
                for (int i = size_; i < size; i++) {  
                   data_[i] = T(); // default insertable  
                }
				size_ = size;
				end_ = &data_[size_];
			}
			else {
				capacity_ = size;
				T* temp = new T[size];
				for (int i = 0; i < size_; i++) {
					temp[i] = data_[i];
				}
				for (int i = size_; i < size; i++) {
					temp[i] = T(); //def
				}
				delete[] data_;
				data_ = temp;
				begin_ = data_;
				size_ = size;
				end_ = &data_[size_];
			}
		}
	}
	/**
	* @brief Resizes the vector to a size. New elements will have value as a value.\n
	* @param size - size to resize to. \n
	* @param value - value to assign to new elements. 
	*/
	void resize(const int& size, const T& value) {
		if (size == size_) return;
		else if (size < size_) {
			for (int i = size; i < size_; i++) {
				~data_[i];
			}
			size_ = size;
			end_ = &data_[size_];
		}
		else if (size > size_) {
			if (size <= capacity_) {
				for (int i = size_; i < size; i++) {
					data_[i] = value;
				}
				size_ = size;
				end_ = &data_[size_];
			}
			else {
				capacity_ = size;
				T* temp = new T[size];
				for (int i = 0; i < size_; i++) {
					temp[i] = data_[i];
				}
				for (int i = size_; i < size; i++) {
					temp[i] = value;
				}
				delete[] data_;
				data_ = temp;
				begin_ = data_;
				size_ = size;
				end_ = &data_[size_];
			}
		}
	}
};
