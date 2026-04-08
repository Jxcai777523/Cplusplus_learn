#include"Date.h"
//测试+ += -=
void test01()
{
	Date d1;
	Date d2 = d1 - 100;
	cout << d1 - d2;
	/*d1.Print();
	d2.Print();
	Date ret=d1 + 10;
	d1.Print();
	ret.Print();
	d1 += 10;
	d1.Print();
	d1 -= 100;
	d1.Print();*/
}
void test02()
{
	/*Date d1;
	d1.operator<<(cout);
	d1 << cout;*/
	//这里发现与我们调用时是反的，由于this指针的存在，那我们尝试写全局函数重载
	//但是因为成员变量是私有型，如果我们的全局函数想要调用那么就需要写get函数
	//这样就比较复杂了，C++中有友元函数可以支持调用
	Date d1;
	Date d2 = d1 - 100;
	d1.Print();
	cin >> d1;

	cout << d1 << d2;
}
int main()
{
	test01();
	//test02();
}