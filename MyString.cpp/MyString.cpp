#include "pch.h"
#include "MyString.h"

namespace strPARK {
	MyString::MyString(int size) : capacity(50), used(0) {
		content = new char[capacity];
	}

	MyString::MyString(char c) : capacity(1), used(1) {
		content = new char[1];
		content[0] = c;
	}

	MyString::MyString(const MyString& other) : capacity(other.capacity), used(other.capacity) {
		content = new char[capacity];
		for (int i = 0; i < used; i++) {
			content[i] = other.content[i];
		}
	}


	MyString::~MyString() {
		delete[] content;
	}

}	// strPARK
