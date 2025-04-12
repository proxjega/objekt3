#pragma once

class Vector {
private:
	int size_;
	int capacity_;
	int* data_;
public:
	Vector();
	~Vector();
};