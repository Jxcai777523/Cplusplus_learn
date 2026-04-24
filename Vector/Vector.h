#pragma once
#include<iostream>
#include<assert.h>
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
			if (capacity > size())
			{
				_end_of_storage = _finish;
			}
		}
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{

			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				memcpy(tmp, _start, size()*sizeof(T));//逐字节拷贝
				delete[] _start;
				_start = tmp;
				//_finish = tmp + size();//这里的_start已经指向了新空间了，调用size()会出现问题
				//解决办法是将原来的空间的长度保存起来
				_finish = tmp + old_size;
				_end_of_storage = _start + n;
			}
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
}