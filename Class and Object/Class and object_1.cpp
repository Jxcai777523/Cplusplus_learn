#define _CRT_SECURE_NO_WARNINGS

//C语言中实现栈的基本操作

//#include<stdio.h>
//typedef struct Stack 
//{
//	int* arr;
//	int capacity;
//	int top;
//}St;
//void InitStack(St* st);
//void StackPush(Stack* ps, int x);
//int StackTop(Stack* ps);
////等等函数

//对栈类的大概定义

//#include<iostream>
//using namespace std;
//class stack
//{
//public:
//	void Init(int n);
//private:
//	int* _arr;
//	int _capacity;
//	int _top;
//};
//void stack::Init(int n)
//{
//	_arr = (int*)malloc(sizeof(int) * n);
//	if (_arr == nullptr)
//	{
//		return;
//	}
//	_capacity = n;
//	_top = 0;//指向栈顶的下一位
//}
//int main()
//{
//
//	return 0;
//}


//写一个时间类，同时包含初始化以及打印成员函数

//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/ " << _month << "/ " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2026, 3, 31);
//	d1.Print();
//	d2.Init(2026, 4, 1);
//	d2.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		;
//	}
//};
//int main()
//{
//	A a;
//	cout << sizeof(a) << endl;
//	return 0;
//}

//判断程序状态

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}
//

//C语言与C++实现栈的比较
//C语言实现栈

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//typedef int StackDatatype;
//typedef struct stack
//{
//	StackDatatype* arr;
//	int capacity;
//	int top;//指向栈顶的下一个位置
//}St;
//
//void StackInit(St* st)
//{
//	assert(st);
//	st->arr = NULL;
//	st->top = st->capacity = 0;
//}
//void StackDestroy(St* st)
//{
//	assert(st);
//	free(st->arr);
//	st->arr = NULL;
//	st->capacity = st->top = 0;
//}
//void StackPush(St* st, StackDatatype data)
//{
//	assert(st);
//	//因为top是从0开始的，如果top=capacity=4,那么从0到3都已经满了
//	//说明空间已经满了，就需要扩容
//	if (st->top == st->capacity)
//	{
//		int newcapacity = st->capacity == 0 ? 4 : 2 * st->capacity;
//		StackDatatype* tmparr = (StackDatatype*)realloc(st->arr, sizeof(StackDatatype) * newcapacity);
//		if (tmparr == NULL)
//		{
//			perror("realloc failed");
//			return;
//		}
//		st->capacity = newcapacity;
//		st->arr = tmparr;
//	}
//	st->arr[st->top++] = data;
//}
//void StackPop(St* st)
//{
//	assert(st && st->top != 0);
//	st->top--;
//}
//StackDatatype StackTop(St* st)
//{
//	assert(st && st->top != 0);
//	return st->arr[st->top-1];//top-1
//}
//bool StackEmpty(St* st)
//{
//	assert(st);
//	if (st->top == 0)
//		return true;
//	return false;
//	//return st->top == 0;
//}
//int StackSize(St* st)
//{
//	assert(st);
//	return st->top;
//}
//int main()
//{
//	St st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	while (!StackEmpty(&st))
//	{
//		printf("%d  ", StackTop(&st));
//		StackPop(&st);
//	}
//	StackDestroy(&st);
//	return 0;
//}


//C++实现栈
//#include<iostream>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//using namespace std;
//typedef int StackDatatype;
//class Stack
//{
//public:
//	void Init();
//	void Destroy();
//	void Push(StackDatatype data);
//	void Pop();
//	StackDatatype Top();
//	bool Empty();
//private:
//	StackDatatype* _arr;
//	int _capacity;
//	int _top;
//};
//void Stack::Init()
//{
//	_arr = nullptr;
//	_capacity = _top = 0;
//}
//void Stack::Destroy()
//{
//	free(_arr);
//	_arr = nullptr;
//	_top = _capacity = 0;
//}
//void Stack::Push(StackDatatype data)
//{
//	if (_top == _capacity)
//	{
//				int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
//				StackDatatype* tmparr = (StackDatatype*)realloc(_arr, sizeof(StackDatatype) * newcapacity);
//				if (tmparr == NULL)
//				{
//					perror("realloc failed");
//					return;
//				}
//				_capacity = newcapacity;
//				_arr = tmparr;
//	}
//			_arr[_top++] = data;
//}
//void Stack::Pop()
//{
//	assert(_top);
//	_top--;
//}
//bool Stack::Empty()
//{
//	return _top == 0;
//}
//StackDatatype Stack::Top()
//{
//	assert(_top);
//	return _arr[_top - 1];
//}
//int main()
//{
//	Stack s1;
//	s1.Init();
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	s1.Push(5);
//	while (!s1.Empty())
//	{
//		cout << s1.Top() << endl;
//		s1.Pop();
//	}
//	s1.Destroy();
//	return 0;
//}