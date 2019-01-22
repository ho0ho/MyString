#include "MyString.h"
#include <iostream>
using namespace std;

namespace strPARK {
	MyString::MyString(int size) : capacity(size), used(0) {
		content = new char[capacity];
	}

	MyString::MyString(char c) : capacity(1), used(1) {
		content = new char[1];
		content[0] = c;
	}

	MyString::MyString(const char *c_str) : capacity(strlen(c_str)), used(strlen(c_str) + 1) {
		content = new char[capacity];
		for (int i = 0; i < used; i++) {
			content[i] = c_str[i];
		}
	}

	MyString::MyString(const MyString& other) : capacity(other.capacity), used(other.capacity) {
		content = new char[capacity];
		for (int i = 0; i < used; i++) {
			content[i] = other.content[i];
		}
	}

	int MyString::getUsed() const { return used; }
	int MyString::getCapacity() const { return capacity; }

	void MyString::print() const {
		for (int i = 0; i < used; i++) {
			cout << content[i];
		}
	}

	void MyString::println() const {
		print();
		cout << endl;
	}

	MyString& MyString::subStr(int start, int end) {	// start <= i < end
		if (start < 0 || end > used && start >= end) {
			cout << "index error" << endl;
			exit(1);
		}

		MyString newStr(end - start + 1);
		for (int i = 0; i < end - start; i++)
			newStr.content[i] = content[start + i];
		newStr.used = end - start;
		return newStr;
	}

	MyString& MyString::concatStr(const MyString& right) {
		if (capacity < used + right.used) {
			delete[] content;
			capacity = used + right.used;
			content = new char[capacity];
		}

		used += right.used;
		for (int i = 0; i < right.used; i++)
			content[used + i] = right.content[i];

		return *this;
	}

	MyString& MyString::operator + (const MyString& right) {
		concatStr(right);
	}

	MyString& MyString::assign(const MyString& right) {
		if (*this == right) {
			return *this;
		}

		if (capacity < right.capacity) {
			delete[] content;
			capacity = right.capacity;
			content = new char[capacity];
		}

		used = right.used;
		for (int i = 0; i < used; i++) {
			content[i] = right.content[i];
		}

		return *this;
	}

	MyString& MyString::operator = (const MyString& right) {
		assign(right);
	}

	bool MyString::operator == (const MyString& right) const {
		size_t i;
		if (used != right.used) return false;
		for (i = 0; i < used && content[i] == right.content[i]; i++);
		return (i == used);
	}

	bool MyString::operator != (const MyString& right) const {
		return !(*this == right);
	}

	bool MyString::operator > (const MyString& right) const {
		int minUsed = (used > right.used) ? right.used : used;

		int i = -1;
		while (++i < minUsed) {
			if (content[i] > right.content[i]) return true;
		}

		if (minUsed == used) return true;
		else return false;
	}

	bool MyString::operator >= (const MyString& right) const {
		return (*this > right || *this == right);
	}

	bool MyString::operator < (const MyString& right) const {
		return !(*this >= right);
	}

	bool MyString::operator <= (const MyString& right) const {
		return !(*this > right);
	}

	char& MyString::at(int index) {
		if (index < 0 || index >= used) {
			cout << "error on at()" << endl;
			exit(1);
		}

		return content[index];
	}

	char& MyString::operator [] (int index) {
		at(index);
	}

	MyString::~MyString() {
		delete[] content;
	}

}	// strPARK
