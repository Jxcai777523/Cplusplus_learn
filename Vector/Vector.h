#pragma once
#include<iostream>
#include<assert.h>
#include<string>
#include<stdbool.h>
using namespace std;

namespace mine
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;//迭代器
		typedef const T* const_iterator;
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}
		vector(const vector<T>& v)
		{
			reserve(v.size());
			for (auto& it : v)//使用引用是为了防止多次拷贝
			{
				push_back(it);
			}
		}
		//可以使用其他类型的迭代器，将数据放入vector中
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			InputIterator in = first;
			while (in != last)
			{
				push_back(*in);
				in++;
			}
		}
		vector(int n, const T& val = T())
		{
			for (size_t i = 0;i < n;i++)
			{
				push_back(val);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//v1=v2
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				vector<T> tmp(v);   // 拷贝构造
				swap(tmp);          // 交换内部指针
			}
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty() const
		{
			return size() == 0;
		}
		void shrink_to_fit()
		{
			if (capacity() > size())
			{
				_end_of_storage = _finish;
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				/*memcpy(tmp, _start, size()*sizeof(T));*///逐字节拷贝
				for (int i = 0;i < old_size;i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
				_start = tmp;
				//_finish = tmp + size();//这里的_start已经指向了新空间了，调用size()会出现问题
				//解决办法是将原来的空间的长度保存起来
				_finish = tmp + old_size;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, T val = T())
		{
			if (n <size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _end_of_storage)
				{
					*(_finish++) = val;
				}
			}
		}
		iterator insert(iterator pos, const T& val)
			//这里的pos指向的是原对象，如果进行了扩容，那么就会产生错误
			//所以我们需要存储pos位置在顺序表中的相对位置
		{
			assert(pos >= _start&& pos <= _finish);
			if (size() == capacity())
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish-1;//_finish指向的最后一个元素的最后一个字节
			while (end > pos)
			{
				*(end+1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
			return pos;
		}
		void push_back(const T& val)//防止当T为非内置类型时，进行多次拷贝所以采用引用
		{
			if (size() == capacity())
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish++ = val;
		}
		void pop_back()
		{
			assert(size());
			_finish--;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		const T& operator[](size_t n) const
		{
			assert(n < size());
			return _start[n];
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
	private:
		//我们观察vector的源码发现
		//其底层是由三个迭代器实现的，但其实我们还是可以将其看成顺序表
		iterator _start;//指向第一个
		iterator _finish;//指向最后一个有效元素
		iterator _end_of_storage;//指向容器中的最后一个有效空间
		//T* _arr;
		//int _size;
		//int _capacity;
	};
	//我们尝试写一个打印的
	/*void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}*/
	//我们发现上面的函数只能实现vector<int>,那我们尝试和写一个函数模板
	template<class T>
	void print_vector(const vector<T>& v)
	{
		//类模板没有实例化时不要取类中的成员，编译器编译时不知道是类型还是静态成员变量，除非加上typename
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			it++;
		}
		cout << endl;
	}
	
}