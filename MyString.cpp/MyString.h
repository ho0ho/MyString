#pragma once

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
		MyString(const char *str);
		MyString(const MyString& other);

		int getUsed() const;
		void print() const;
		void println() const;
		MyString& subStr(int start, int end);

		MyString& concatStr(const MyString& right);		
//		MyString& operator + (const MyString& right);
		MyString& assign(MyString& right);
//		MyString& operator = (MyString& right);
		bool operator == (const MyString& right) const;
		bool operator != (const MyString& right) const;
		bool operator > (const MyString& right) const;
		bool operator < (const MyString& right) const;
		bool operator >= (const MyString& right) const;
		bool operator <= (const MyString& right) const;

		virtual ~MyString();
	};

} // strPARK

#endif	// _MYSTRING_H_

