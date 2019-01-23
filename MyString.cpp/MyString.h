#pragma once

#include <iostream>

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

namespace strPARK {
	class MyString 
	{
	protected:
		char *content;
		int capacity;		// memory_allocation
		int used;			// length
	public:
		MyString(int size = 50);
		MyString(char c);
		MyString(const char *c_str);
		MyString(const MyString& other);

		int getUsed() const;
		int getCapacity() const;
//		void print() const;
//		void println() const;

		const MyString subStr(int start, int end);

		const MyString operator + (const MyString& right);
		MyString& operator = (const MyString& right);
		MyString& operator += (const MyString& right);
		bool operator == (const MyString& right) const;
		bool operator != (const MyString& right) const;
		bool operator > (const MyString& right) const;
		bool operator < (const MyString& right) const;
		bool operator >= (const MyString& right) const;
		bool operator <= (const MyString& right) const;
		char& operator [] (int index);

		// friend method(not member) with inline
		friend ostream& operator << (ostream& outStream, const MyString& out) {
			if (out.used == 0) {
				outStream << "empty string" << endl;
				return;
			}
			for (int i = 0; i < out.used; i++)
				outStream << out[i];
			outStream << " => used: " << out.used << ", capacity: " << out.getCapacity << endl;
		}

		MyString& insert(int loc, const MyString& str);
		MyString& insert(int loc, const char *c_str);
		MyString& insert(int loc, char c);

		MyString& erase(int loc, int num);

		int find(int find_from, const MyString& str);
		int find(int find_from, const char *c_str);
		int find(int find_from, char c);

		virtual ~MyString();
	};

} // strPARK

#endif	// _MYSTRING_H_

