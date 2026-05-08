#pragma once
#include<iostream>
#include<stdbool.h>
#include<assert.h>
namespace mine
{
	template<class T>
	struct list_node//成员默认为公有，便于后面的访问
	//存在其他方法，可以利用友元或者内部类解决，但是我们观察源码发现是分别封装的，所以我们也分开来写
	{
		list_node(const T data=T())//若构造结点时未传入数据，则默认以list容器所存储类型的默认构造函数所构造出来的值为传入数据。
			:_data(data),_next(nullptr),_prev(nullptr)
		{ }
		//成员变量
		T _data;
		list_node<T> _next;//前驱指针
		list_node<T> _prev;//后继指针
	};
	template<class T>
	struct list_iterator  //普通迭代器的实现
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> Self;
		list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return  _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		//成员变量
		Node* _node;
	};
	template<class T>
	struct list_const_iterator  //普通迭代器的实现
	{
		typedef list_node<T> Node;
		typedef list_const_iterator<T> Self;
		list_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return  _node->_data;
		}

		const T* operator->()
		{
			return &_node->_data;
		}

		const Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		const Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		//成员变量
		Node* _node;
	};
	template<class T, class Ref, class Ptr>
	class list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;//引用 指针

		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()//前置++
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator++(int)//后置++，加int形参
		{
			Self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		Node* _node;
	};
	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		bool empty() const
		{
			return _size == 0;
		}

		size_t size() const
		{
			return _size;
		}

		T& front()
		{
			assert(_size!=0);//链表不能只有一个哨兵位的头结点
			return _head->_next->_data;
		}
		const T& front() const
		{
			assert(_size != 0);
			return _head->_next->_data;
		}

		T& back()
		{
			assert(_size != 0);
			return _head->_prev->_data;
		}
		const T& back() const
		{
			assert(_size != 0);
			return _head->_prev->_data;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos._node); //检测pos的合法性

			Node cur = pos.node;
			Node newnode = new node(val);
			newnode._prev = cur._prev;
			  
		}
		void push_back(const T& val)
		{
			Node ptail = _head->_prev;
			Node newnode = new Node;
			newnode->_data = val;
			newnode->_prev = ptail;
			newnode->_next = _head;
			ptail->_next = newnode;
			_head->_prev = newnode;
		}
	private:
		Node* _head;
		int _size;
	};
}