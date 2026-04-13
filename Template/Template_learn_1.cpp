//泛型编程的概念

//#include<iostream>
//using namespace std;
//void Swap(int& x,int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}
//void Swap(char& x, char& y)
//{
//	char tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int x1 = 1, y1 = 2;
//	Swap(x1, y1);
//	double x2 = 1.1, y2 = 2.2;
//	Swap(x2, y2);
//	char x3 = 'a', y3 = 'b';
//	Swap(x3, y3);
//	return 0;
//}

//利用函数模板实现上述的功能
//#include<iostream>
//using namespace std;
////template<class T>
//template<typename T>//声明一种模板变量的名称为T
////那如果要声明两种就是
////template<class T1,class T2>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
////那如果要声明两种就是
//template<class T1,class T2>
//T1& Add(T1& x, T2& y)
//{
//	return x + y;
//}
//int main()
//{
//	int x1 = 1, y1 = 2;
//	Swap(x1, y1);//这里在调用函数时，编译器会自己辨别变量的类型，那么T就会自行转换了
//	double x2 = 1.1, y2 = 2.2;
//	Swap(x2, y2);
//	Add(x1, x2);
//	Add(y1, y2);
//	char x3 = 'a', y3 = 'b';
//	Swap(x3, y3);
//	return 0;
//}


//显示调用的实例化展示
//#include<iostream>
//using namespace std;
//template<class T>
//T Add(T x, T y)
//{
//	return x + y;
//}
//int main()
//{
//	int x = 1;
//	double y = 1.2;
//	Add<int>(x, y);
//	return 0;
//}


//模板参数的匹配原则
//已经存在了完全适配的函数，那么就不需要再通过函数模板再进行创建
//#include<iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//int main()
//{
//	int x = 1, y = 2;
//	Add(x, y);       
//	return 0;
//}

//选取最适配的函数,其实这里第一种也是不匹配第二个实例的
//所以才会选模板函数
//#include<iostream>
//using namespace std;
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数 
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化 
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的 
//}


//类模板
//写一个stack类
//#include<iostream>
//using namespace std;
//template<class T>
//class stack
//{
//public:
//	stack(int n=4)
//	{ 
//		_arr = new T[n];
//		_top = 0;
//		
//		_capacity = n;
//	}
//	~stack()
//	{
//		delete[] _arr;
//		_top = 0;
//		_capacity = 0;
//	}
//	void push(const T& n)
//	{
//		if (_top == _capacity)
//		{
//			T* tmp = new T[_capacity * 2];
//			memcpy(tmp, _arr, sizeof(T) * _top);
//			delete[] _arr;
//			_arr = tmp;
//			_capacity *= 2;
//		}
//		_arr[_top++] = n;
//	}
//private:
//	T* _arr;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	stack<int> s1;
//	s1.push(1);
//	return 0;
//}



//隐式实例化展示
//#include<iostream>
//using namespace std;
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化 
//	Add(a1, (int)d1);
//	return 0;
//}