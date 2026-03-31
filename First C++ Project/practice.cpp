#define _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#include<iostream>//包含了printf scanf函数
////using namespace std;使用std域，就不需要使用std::
//int main()
//{
//	printf("Hello C World\n");
//	std::cout << "Hello C World\n";
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello C++ World!" << endl;
//	return 0;
//}
//C语言中的命名冲突问题
//#include<stdio.h>
//namespace ccc 
//{
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//int main()
//{
//	printf("%d", ccc::Add(9,1));
//	return 0;
//}
//#include<iostream>
//namespace wxuc
//{
//	namespace stu
//	{
//		int a = 18;
//	}
//	int b = 19;
//}
//using wxuc::b;
//int main()
//{
//	std::cout << wxuc::b << std::endl << b<< std::endl;
//	return 0;
//}
//C++的输入输出展示
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello C++ World!" << endl;
//	int a, b;
//	cout << "请输入a的值" << endl;
//	cin >> a;
//	printf("请输入b的值\n");
//	scanf("%d", &b);
//	cout << "a: "<<a << " b: " << b << endl;
//	printf("a: %d b: %d", a, b);
//	return 0;
//}
//缺省参数

//#include <iostream>
//#include <assert.h>
//using namespace std;
// void Func(int a = 0)
// {
//	 cout << a << endl;
// }
//
//int main()
//{
//	Func(); // 没有传参时，使⽤参数的默认值
//	Func(10); // 传参时，使⽤指定的实参
//	
//	return 0; 
//}


//#include<iostream>
//using namespace std;
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//void Func2(int a, int b = 20, int c = 30)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	cout << "c= " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(40);
//	Func1(40, 50);
//	Func1(40, 50, 60);
//	//只能从到右依次进行赋值，不能跳跃进行赋值
//	Func2(10);
//	Func2(40,50,60);
//	return 0;
//}
//#include<stdio.h>
//int Addi(int a, int b)
//{
//	return a + b;
//}
//double Addd(double a, double b)
//{
//	return a + b;
//}
//int main()
//{
//	printf("%d\n", Addi(1,2));
//	printf("%f\n", Addd(1.2, 3.4));
//	return 0;
//}


//C++中函数重载实现上面的代码

//#include<iostream>
//using namespace std;
//double Add(double x, double y)
//{
//	return x + y;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	cout << Add(1.2, 3.4) << endl;
//	cout << Add(1, 2) << endl;
//
//	return 0;
//}

//C++中的引用

//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& pa = a;
//	cout << a <<' '<< pa << endl;
//	pa = 12;
//	cout << a << ' ' << pa << endl;
//	return 0;
//}
//引用的特性
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	// 编译报错：“ra”: 必须初始化引⽤
//	//int& ra;
//	int& b = a;
//	int c = 20;
//	// 这⾥并非让b引⽤c，因为C++引⽤不能改变指向，
//	// 这⾥是⼀个赋值
//	b = c;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	return 0;
//}
//引用实现值交换函数
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int& p = 10;//这里10是一个常值，别名p把权限放大了
//	const int& pp = 10;
//	int a = 10;
//	const int& r = a;
//	//这里别名r的只读不能修改，权限缩小，但是是允许的
//}

//权限放大缩小问题

#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	const int& ra = 30;
	// 编译报错: “初始化”: ⽆法从“int”转换为“int &”
	int& rb = a * 3;
	const int& rb = a * 3;
	double d = 12.34;
	// 编译报错：“初始化”: ⽆法从“double”转换为“int &”
	int& rd = d;
	const int& rd = d;
	return 0;
}