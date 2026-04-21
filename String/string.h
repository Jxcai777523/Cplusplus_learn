#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
namespace mine
{
	class string
	{
	public:
		//短小常用的函数可以直接写在类里，
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		string()
		{
			_str = new char[1] {'\0'};
			_capacity = 0;
			_size = 0;
		}
		string(const char* str)
		{
			assert(str);
			int len = strlen(str);
			_size = _capacity = len;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)//拷贝构造
		{
			_str = new char[s._capacity + 1];//1的空间是留给/0的
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		//赋值运算符重载
		string& operator = (const char* str)
		{
			assert(str);
			int len = strlen(str);
			char* tmp = new char[len + 1];
			strcpy(tmp, str);
			delete[] _str;
			_str = tmp;
			_size = len;
			_capacity = len;
			return *this;
		}
		string& operator=(const string& s)
		{
			if (&s != this)
			{
				*this = s._str;
			}
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		size_t size() const
		{
			return _size;
		}
		size_t length() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		const char* c_str() const
		{
			return _str;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		//访问函数的实现
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& at(size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& front()
		{
			return _str[0];
		}
		char& back()
		{
			assert(_size > 0);
			return _str[_size-1];
		}
		//修改
		void reserve(size_t n = 0);
		string operator+(const char* str);
		string operator+(const string& s);
		string& operator += (const char* str);
		string& operator +=(const char ch);
		string& operator += (const string& s);
		string& append(const char* s);
		string& append(const string& str);
		string& append(const string& str, size_t subpos, size_t sublen);
		void push_back(char c);
		void pop_back();
		string& insert(size_t pos, const string& str);
		string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
		string & insert(size_t pos, const char* s);
		string& erase(size_t pos = 0, size_t len = npos);

		size_t find(const string& str, size_t pos = 0) const;
		size_t find(const char* s, size_t pos = 0) const;
		size_t find(char ch, size_t pos=0);

		string substr(size_t pos = 0, size_t len = npos) const;

		
	private:
		static const size_t npos;
		char* _str=nullptr;
		size_t _size=0;//_size以及_capacity不包含/0的空间
		size_t _capacity=0;//_size代表数量，_capacity代表容量，_str[size]是'/0'
	};

	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	istream& operator>> (istream& in, string& str);
	ostream& operator<< (ostream& out, const string& str);

	istream& getline(istream& is, string& str);
}