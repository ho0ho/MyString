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

	MyString::MyString(const char *c_str) : capacity(strlen(c_str)), used(strlen(c_str)) {
		content = new char[capacity];
		for (int i = 0; i < used; i++) {
			content[i] = c_str[i];
		}
	}

	MyString::MyString(const MyString& other) : capacity(other.capacity), used(other.used) {
		content = new char[capacity];
		for (int i = 0; i < used; i++) {
			content[i] = other.content[i];
		}
	}

	int MyString::getUsed() const { return used; }
	int MyString::getCapacity() const { return capacity; }

	// const리턴: 외부로 반환되어야 하는 newStr가 지역적으로 선언되어있기 때문에 &없이, 즉 리턴될 때 복사되어야 함
	const MyString MyString::subStr(int start, int end) {	// start <= i < end
		if (start < 0 || end > used && start >= end) {
			cout << "index error" << endl;
			exit(1);
		}

		MyString newStr(end - start + 1);
		for (int i = 0; i < newStr.capacity; i++)
			newStr.content[i] = content[start + i];
		newStr.used = newStr.capacity;
		return newStr;
	}

	// const리턴: 외부로 반환되어야 하는 sumStr가 지역적으로 선언되어있기 때문에 &없이, 즉 리턴될 때 복사되어야 함
	const MyString MyString::operator + (const MyString& right) {
		int sumCapacity = right.used + used;
		MyString sumStr(sumCapacity);
		sumStr.used = sumCapacity;

		for (int i = 0; i < used; i++) 
			sumStr.content[i] = content[i];
		for (int i = 0; i < right.used; i++) 
			sumStr.content[used + i] = right.content[i];
		
		return sumStr;
	}

	MyString& MyString::operator = (const MyString& right) {
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

	MyString& MyString::operator += (const MyString& right) {
		*this = *this + right;
		return *this;
	}

	bool MyString::operator == (const MyString& right) const {
		size_t i;
		if (used != right.used) return false;
		for (i = 0; (i < used) && (content[i] == right.content[i]); i++);
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

		if (minUsed == right.used) return true;
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

	char& MyString::operator [] (int index) {
		if (index < 0 || index >= used) {
			cout << "error on operator []" << endl;
			exit(1);
		}
		return content[index];
	}

	MyString& MyString::insert(int loc, const MyString& str) {
		if (loc < 0 || loc >= used) {
			cout << "error: wrong index in insert()" << endl;
			exit(1);
		}

		if (capacity < str.used + used) {
			capacity = str.used + used;
			char *save = content;
			content = new char[capacity];
			for (int i = 0; i < loc; i++) 
				content[i] = save[i];
			for (int i = 0; i < str.used; i++)
				content[i + loc] = str.content[i];
			for (int i = 0; i < used - loc; i++)
				content[i + loc + str.used] = save[loc + i];
			delete[] save;
			used = capacity;
		}
		else {
			for (int i = used - loc - 1; i >= 0; i--)
				content[i + loc + str.used] = content[i + loc];
			for (int i = 0; i < str.used; i++)
				content[i + loc] = str.content[i];
			used += str.used;
		}
		return *this;
	}

	MyString& MyString::insert(int loc, const char *c_str) {
		MyString str(c_str);
		return insert(loc, str);
	}

	MyString& MyString::insert(int loc, char c) {
		MyString str(c);
		return insert(loc, str);
	}

	MyString& MyString::erase(int loc, int num) {
		if (loc < 0 || loc >= used || num < 0 || num >= used) {
			cout << "error arguments in erase()" << endl;
			exit(1);
		}

		for (int i = loc; i < used - loc; i++)
			content[i] = content[i +  num];

		used -= num;
		return *this;
	}

	int MyString::find(int find_from, const MyString& str) {
		if (find_from < 0 || find_from >= used) {
			cout << "error arguments on find()" << endl;
			exit(1);
		}

		int i, j;
		for (i = find_from; i < used - str.used; i++) {
			for (j = 0; j < str.used; j++) {
				if (content[i + j] != str.content[j]) break;
			}
			if (j == str.used) return i;
		}

		return -1;		
	}

	int MyString::find(int find_from, const char *c_str) {
		MyString str(c_str);
		return find(find_from, str);
	}

	int MyString::find(int find_from, char c) {
		MyString str(c);
		return find(find_from, str);
	}

	MyString::~MyString() {
		delete[] content;
	}
}	// strPARK
