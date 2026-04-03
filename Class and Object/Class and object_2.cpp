#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	date()
//	{
//		_year= 1949;
//		_month = 10;
//		_day = 1;
//		cout << "无参构造" << endl;
//	}
//	date(int year,int month=10,int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	 cout << "半缺省构造" << endl;
//	}
//	//date(int year=1949,int month=10,int day=1)//这里最好就用全缺省的默认构造函数
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	// cout << "全缺省构造" << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//int main()
//{
//	date d1;
//	/*date d2(1949);
//	date d3;*/
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class stack
//{
//public:
//	stack()//我这里为了方便，就直接初始化容量为4
//	{
//		_arr = (int*)malloc(sizeof(int)*4);
//		_capacity = 4;
//		_top = 0;
//		cout << "stack()" << endl;
//	}
//	~stack()
//	{
//		free(_arr);
//		_arr = nullptr;
//		_capacity = _top = 0;
//		cout << "~stack()" << endl;
//	}
//private:
//	int* _arr;
//	int _capacity;
//	int _top;
//};
//
//class MyQueue
//{
//public:
//	~MyQueue()
//	{
//		cout << "~MyQueue()" << endl;;
//	}
//private:
//	stack _pushstack;
//	stack _popstack;
//};
//int main()
//{
//	MyQueue q1;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	//这里再提一嘴，当我们调用类成员函数时，会有一个隐式的this指针
//	//date* const this
//	date(int year=2000,int month=1,int day=1)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//	//这里的d,是被拷贝对象的别名
//	//那为什么非要用引用？
//	//逻辑上会造成无限递归，编译器会报错
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//	/*date(const date& d)
//	{
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Func1(date d)
//{
//	cout << &d << endl;
//	cout << "Func1" << endl;
//}
//int main()
//{
//	date d1;
//	d1.Print();
//	/*Func1(d1);*/
//	date d2(d1);
//	d2.Print();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class stack
//{
//public:
//	stack()
//	{
//		_arr = (int*)malloc(sizeof(int) * 4);
//		_capacity = 4;
//		_top = 0;
//	}
//	~stack()
//	{
//		free(_arr);
//		_arr = nullptr;
//		_capacity = _top = 0;
//	}
//	stack(const stack& s)
//	{
//		_arr = (int*)malloc(sizeof(int) * s._capacity);
//		_top = s._top;
//		_capacity = s._capacity;
//		memcpy(_arr, s._arr, sizeof(int) * s._top);
//	}
//private:
//	int* _arr;
//	int _capacity;
//	int _top;
//};
//stack& Func1(stack s)
//{
//	stack s3(s);
//	return s3;
//}
//int main()
//{
//	stack s1;
//	stack s2(s1);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	date(int year=2000,int month=1,int day=1)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//	//其实对于date类来说，这里不使用拷贝构造也没问题
//	date(const date& d)
//	{
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//	}
//	//因为类的成员函数会有隐式的this指针
//	//它的第⼀个运算对象默认传给隐式的this指针，
//	// 因此运算符重载作为成员函数时，参数⽐运算对象少⼀个
//	bool operator ==(date& d)
//	{
//		return _year == d._year&&
//			_month == d._month 
//			&&_day == d._day;
//	}
//	date& operator++()
//	{
//		cout << "前置++" << endl;
//		return *this;
//	}
//	date& operator++(int)
//	{
//		date tmp;
//		cout << "后置++" << endl;
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////在类外实现一个 ==  的重载
////bool operator == (date& d1,date& d2)
////{
////	return d1._year == d2._year &&
////		d1._month == d2._month &&
////		d1._day == d2._day;
////}
//int main()
//{
//	date d1;
//	date d2;
//	if (d1 == d2)
//	{
//		cout << "yes" << endl;
//	}
//	else
//		cout << "no" << endl;;
//	d1++;
//	++d2;
//	return 0;
//}

//赋值运算符重载

//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	date(int year = 2000, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	} 
//	date& operator=(const date& d)
//	{
//		this->_day = d._day;
//		this->_month = d._month;
//		this->_year = d._year;
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	date d1(2026, 4, 3);//这里是调用了全缺省的构造函数
//	d1.Print();
//	date d2;
//	d2.Print();
//	d1 = d2;//d1.operator=(d2);
//	d1.Print();
//	return 0;
//}

//自定义类型的赋值重载

#include<iostream>
using namespace std;
class stack
{
public:
	stack()
	{
		_arr = (int*)malloc(sizeof(int) * 4);
		_capacity = 4;
		_top = 0;
	}
	~stack()
	{
		free(_arr);
		_arr = nullptr;
		_capacity = _top = 0;
	}
	stack(const stack& s)//拷贝构造
	{
		_arr = (int*)malloc(sizeof(int) * s._capacity);
		_top = s._top;
		_capacity = s._capacity;
		memcpy(_arr, s._arr, sizeof(int) * s._top);
	}
	stack& operator=(const stack& s)
	{
		int* tmp = (int*)malloc(sizeof(int) * s._capacity);
		_top = s._top;
		_capacity = s._capacity;
		free(_arr);
		_arr = tmp;
		memcpy(_arr, s._arr, sizeof(int) * s._top);
		return *this;
	}
	int* _arr;
	int _capacity;
	int _top;
};
class MyQueue
{
private:
	stack popstack;
	stack pushstack;
};
int main()
{
	stack s1;
	s1._top = 2;
	stack s2;
	s2 = s1;
	return 0;
}