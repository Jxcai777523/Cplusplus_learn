#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	//date()
//	//{
//	//	_year= 1949;
//	//	_month = 10;
//	//	_day = 1;
//	//	cout << "无参构造" << endl;
//	//}
//	//date(int year,int month=10,int day=1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	// cout << "半缺省构造" << endl;
//	//}
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

#include<iostream>
using namespace std;
class stack
{
public:
	//stack()//我这里为了方便，就直接初始化容量为4
	//{
	//	_arr = (int*)malloc(sizeof(int)*4);
	//	_capacity = 4;
	//	_top = 0;
	//}
private:
	int* _arr;
	int _capacity;
	int _top;
};

class MyQueue
{
public:

private:
	stack _pushstack;
	stack _popstack;
};
int main()
{
	MyQueue q1;
	return 0;
}