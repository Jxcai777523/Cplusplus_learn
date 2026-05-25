#pragma once
#include<deque>
#include<vector>
#include<list>
//namespace mine
//{
//	template<class T,class Container=std::vector<T>>
//	class stack
//	{
//	public:
//		bool empty() const
//		{
//			return _con.size()==0;
//		}
//		void push(const T& val)
//		{
//			_con.push_back(val);
//		}
//		void pop()
//		{
//			_con.pop_back();
//		}
//		size_t size() const
//		{
//			return _con.size();
//		}
//		T& top() const
//		{
//			return _con.back();
//		}
//		void swap(stack& st)
//		{
//			_con.swap(st._con);
//		}
//	private:
//		Container _con;
//	};
//
//}
//namespace mine
//{
//	template<class T, class Container = std::deque<T>>
//	class stack
//	{
//	public:
//		bool empty() const
//		{
//			return _con.size() == 0;
//		}
//		size_t size() const
//		{
//			return _con.size();
//		}
//		T& top()
//		{
//			return _con.back();
//		}
//		const T& top() const
//		{
//			return _con.back();
//		}
//		void push(const T& val)
//		{
//			_con.push_back(val);
//		}
//		void pop()
//		{
//			_con.pop_back();
//		}
//		void swap(stack& x)
//		{
//			_con.swap(x._con);
//		}
//	private:
//		Container _con;
//	};
//}
namespace mine
{
	template<class T,class Container=std::deque<T>>
	class queue
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}
		void swap(queue& que)
		{
			_con.swap(que._con);
		}
	private:
		Container _con;
	};
}