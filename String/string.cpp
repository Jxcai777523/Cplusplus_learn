#include"string.h"
namespace mine
{
	const size_t string::npos = -1;
	void string::reserve(size_t n)
	{
		if (_capacity< n)
		{
			char* tmp = new char[n + 1];
			if (_str != nullptr)
			{
				strcpy(tmp, _str);
			}
			else tmp[0] = '\0';
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	string string::operator+(const char* str)
	{
		string tmp=_str;
		tmp += str;
		return tmp;
	}
	string string::operator+(const string& s)
	{
		string tmp=_str;
		tmp += s;
		return tmp;
	}
	string& string::operator +=(const char ch)
	{
		if (_capacity == _size)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}
	string& string::operator += (const char* str)
	{
		if (str == nullptr)
		{
			return *this;
		}
		int len = strlen(str);
		while(_capacity < _size + len)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
		return *this;
	}
	string& string::operator += (const string& s)
	{
		while(_capacity < _size + s._size)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		strcpy(_str + _size, s._str);
		_size += s._size;
		return *this;
	}
	string& string::append(const char* s)
	{
		*this += s;
		return *this;
	}
	string& string::append(const string& s)
	{
		*this += s;
		return *this;
	}
	string& string::append(const string& str, size_t subpos, size_t sublen)
	{
		assert(subpos <= str._size);
		if (sublen == 0)
		{
			return *this;
		}
		if (subpos + sublen > str._size)
		{
			sublen = str._size - subpos;
		}
		while (_capacity < _size + sublen)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		for (int i = 0;i < sublen;i++)
		{
			_str[_size + i] = str._str[subpos + i];
		}
		_size += sublen;
		_str[_size] = '\0';
		return *this;
	}
	void string::push_back(char c)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	void string::pop_back()
	{
		assert(_size > 0);
		_str[--_size] = '\0';
	}
	string& string::insert(size_t pos, const string& str)
	{
		assert(pos < _size);
		while (_capacity < _size + str._size)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		//将*this._str的pos开始的位置向后移动str._size
		for (int i = _size;i >= (int)pos;i--)
		{
			_str[i + str._size] = _str[i];
		}
		for (int i = 0;i < str._size;i++)
		{
			_str[pos + i] = str._str[i];
		}
		_size += str._size;
		return *this;
	}

	string& string::insert(size_t pos, const string& str, size_t subpos, size_t sublen)
	{
		assert(pos < _size && subpos < str._size);
		if (sublen == 0)
		{
			return *this;
		}
		if (subpos + sublen > str._size)
		{
			sublen = str._size - subpos;
		}
		while (_capacity < _size + sublen)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		for (int i = _size;i >= (int)pos;i--)
		{
			_str[i + sublen] = _str[i];
		}
		for (int i = 0;i < sublen;i++)
		{
			_str[pos + i] = str._str[i];
		}
		_size += sublen;
		return *this;
	}
	string& string::insert(size_t pos, const char* s)
	{
		assert(pos < _size);
		int len = strlen(s);
		while (_capacity < _size + len)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		//将*this._str的pos开始的位置向后移动str._size
		for (int i = _size;i >= (int)pos;i--)
		{
			_str[i + len] = _str[i];
		}
		for (int i = 0;i < len;i++)
		{
			_str[pos + i] = s[i];
		}
		_size += len;
		return *this;
	}
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i<=_size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
		return *this;
	}
	size_t string::find(const string& str, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str._str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}
	size_t string::find(char ch, size_t pos)
	{
		assert(pos < _size);

		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str);
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			return ptr - _str;
		}
	}
	string string::substr(size_t pos, size_t len) const
	{
		assert(pos < _size);
		string sub;
		if (len == npos || pos + len > _size) 
		{
			len = _size - pos;
		}
		sub.reserve(len);
		for (size_t i = 0; i < len; ++i) 
		{
			sub += _str[pos + i];
		}
		return sub;
	}
	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	istream& operator>> (istream& in, string& str)
	{
		str.clear();
		char ch;
		ch = in.get();
		//先读取到非空格 换行再进行写入
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}
		while (ch != ' ' && ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
	}
	ostream& operator<< (ostream& out, const string& str)
	{
		for (auto ch : str)
		{
			out << ch;
		}
		return out;
	}
	istream& getline(istream& is, string& str)
	{
		str.clear();
		char ch;
		ch = is.get();
		while (ch != '\n')
		{
			str += ch;
			ch = is.get();
		}
		return is;
	}
}