//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)//非默认构造
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//class Time
//{
//public:
//	Time()
//		: _year(2000),
//		_month(1),
//		_day(1),   //这里后面没有成员变量了，就不需要加  ，
//		_arr((int*)malloc(sizeof(int)*4))  //接表达式也是可以的
//	{
//
//	}
//	void Print()
//	{
//		cout << _year << '/' << _month << '/' << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* _arr;
//
//};
//int main()
//{
//	Time t1;
//	t1.Print();
//	/*const int A;
//	int& b;*/
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a)
//		: _a1(a), _a2(_a1)
//	{}
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//}


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a1)
//		: _a1(a1)
//	{ }
//	A(int a1,int a2)
//		: _a1(a1),_a2(a2)
//	{ }
//	void Print()
//	{
//		cout << _a1 << ' ' << _a2 << endl;
//	}
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1=7;
//	int _a2=7;
//};
//class B
//{
//public:
//	B(const A& a)
//		: _b(a.Get())
//	{ }
//	void Print()
//	{
//		cout << _b << endl;
//	}
//private:
//	int _b=0;
//};
//int main()
//{
//	//这里是 1 通过隐式类型转换(其实就是构造)成一个A类的临时成员变量然后aa1进行拷贝构造
//	//但是编译器会优化成只有一次直接构造
//	A aa1 = 1;
//	aa1.Print();
//	A aa2 = { 1,2 };
//	aa2.Print();
//	B bb1 = aa2;
//	bb1.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a1)
//		: _a1=a1
//	{}
//
//private:
//	int _a1;
//	static int _a2;
//};
//int  A::_a2 = 7;
//int main()
//{
//
//	return 0;
//}

// 实现⼀个类，计算程序中创建出了多少个类对象？
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)//拷贝构造
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	// 类⾥⾯声明
//	static int _scount;
//};
//// 类外⾯初始化
//int A::_scount = 0;
//int main()
//{
//cout << A::GetACount() << endl;
//A a1, a2;
//A a3(a1);
//cout << A::GetACount() << endl;
//cout << a1.GetACount() << endl;
//	
//		// 编译报错：error C2248: “A::_scount”: ⽆法访问 private 成员(在“A”类中声明)
//		//cout << A::_scount << endl;
//		
//return 0;
//}

//友元
//#include<iostream>
//using namespace std;
//class B;//这里先对B进行声明，防止找不到
//class A
//{
//	friend class B;
//	friend void Func(const A& aa, const B& _bb);
//	public:
//	A(int a1,int a2)
//		: _a1(a1),_a2(a2)
//	{ }
//	void Print()
//	{
//		cout << _a1 << ' ' << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//};
//class B
//{
//	friend void Func(const A& aa, const B& bb);
//public:
//		B(int b1, int b2)
//		: _b1(b1), _b2(b2)
//		{ }
//private:
//	int _b1;
//	int _b2;
//};
//void Func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << ' ' << aa._a2 << endl;
//	cout << bb._b1 << ' ' << bb._b2 << endl;
//}
//int main()
//{
//	A aa(1, 2);
//	B bb(2, 3);
//	Func(aa, bb);
//	return 0;
//}

//内部类

//#include<iostream>
//using namespace std;
//class A
//{
//	class B;
//	friend void Func(const A& aa, const A::B& _bb);
//	public:
//	A(int a1,int a2)
//		: _a1(a1),_a2(a2)
//	{ }
//	void Print()
//	{
//		cout << _a1 << ' ' << _a2 << endl;
//	}
//	class B
//	{
//		friend void Func(const A& aa, const B& bb);
//	public:
//		B(int b1, int b2)
//			: _b1(b1), _b2(b2)
//		{
//		}
//	private:
//		int _b1;
//		int _b2;
//	};
//private:
//	int _a1;
//	int _a2;
//};
//void Func(const A& aa, const A::B& bb)
//{
//	cout << aa._a1 << ' ' << aa._a2 << endl;
//	cout << bb._b1 << ' ' << bb._b2 << endl;
//}
//int main()
//{
//	A aa(1, 2);
//	A::B bb(2, 3);
//	aa.Print();
//	Func(aa, bb);
//	return 0;
//}


#include<iostream>
using namespace std;
class A
{
public:
	A(int a)
		: _a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
int main()
{
	A aa1(1);
	A aa2();//这里会看成函数调用

	A aa2(1);
	A (3);
	return 0;
}