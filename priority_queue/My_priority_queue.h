#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
namespace mine
{
	template<class T>
    class Less
    {
    public:
	   bool operator()(const T& x1, const T& x2)
	   {
		   return x1 < x2;
	   }
    };
    template<class T>
    class Greater
    {
    public:
	   bool operator()(const T& x1, const T& x2)
	   {
		  return x1 > x2;
	   }
    };
	template<class T,class Container=std::vector<T>,class compare=Less<T>>
	class priority_queue
	{
	public:
		//用于push
		void AdjustUp(int child)//我们默认建大堆
		{
			int parent = (child - 1) / 2;
			while (child > 0)//当child=0,就一定是最大了，也就调整成堆了
			{
				//_con[child]>_con[parent]
				if (compare()(_con[parent], _con[child]))
				//我们这里使用的是less,就是<,所以需要调换一下顺序
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;//只要有一次满足大堆，那么就实现了
				}
			}
		}
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}
		void AdjustDown(int parent)
		{
			//对于父节点来说，当我们要构造大堆时，我们应该与大的那个孩子进行交换
			int child = parent * 2 + 1;//我们先认为左孩子是大的哪一个
			while (child < _con.size())
				//因为每次都要与孩子比较，当孩子到了叶子节点后，再调整一次就可以了
			{
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				if (child + 1 < _con.size() && compare()(_con[child], _con[child + 1]))
				{
					child++;
				}
				//if (_con[parent] < _con[child])
				if(compare()(_con[parent],_con[child]))
				{
					std::swap(_con[parent],_con[child]);
					parent=child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);

		}
		bool empty() const
		{
			return _con.size() == 0;
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& Top() const
		{
			return _con.front();
		}
		void swap(priority_queue& pq)
		{
			_con.swap(pq._con);
		}
	private:
		Container _con;
	};
}