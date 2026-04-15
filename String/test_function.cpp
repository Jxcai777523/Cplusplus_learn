#include<iostream>
#include<string>
using namespace std;
//string 的底层逻辑是顺序表
//class string
//{
//public:
//	//一系列的成员函数
//	//………………
//private:
//	char* _arr;
//	int _capacity;//不包括/0的大小
//	int _size;//不包括/0的大小
//};
//测试进行实例化
void test1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(s2,5);//这里与下面一个做一个区分
	string s5("hello world", 5);
	string s6(10, '*');
}
void test2()
{
	string s1;
	cin >> s1;cout << s1 << endl;
	string s2;
	getline(cin, s2);cout << s2<<endl;
	string s3;
	getline(cin, s3, '*');cout << s3 << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}