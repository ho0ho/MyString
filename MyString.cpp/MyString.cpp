#include "MyString.h"
#include <iostream>
using namespace std;

namespace strPARK {
	MyString::MyString(int size) : capacity(50), used(0) {
		content = new char[capacity];
	}

	MyString::MyString(char c) : capacity(1), used(1) {
		content = new char[1];
		content[0] = c;
	}

	MyString::MyString(const char *c_str) : capacity(strlen(c_str)), used(strlen(c_str)+1) {
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

		int num = end - start;
		content.substr(start, num);

	}
	


	MyString::~MyString() {
		delete[] content;
	}

}	// strPARK
