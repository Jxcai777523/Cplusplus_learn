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
void test3()//遍历字符串
{
	string s1("hello world");
	for (int i = 0;i < s1.size();i++)
	{
		cout << s1[i]<<' ';
	}
}
void test4()//使用迭代器进行遍历
{
	const string s1("hello world");
	string::const_iterator it = s1.cbegin();
	while (it != s1.cend())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	const string s2(s1);
	string::const_reverse_iterator rit = s2.crbegin();//反向迭代器
	while (rit != s2.crend())
	{
		cout << *rit << ' ';
		rit++;
	}
}
//范围for以及auto
void test5()
{
	string s1("hello world");
	//auto 自动识别ch变量的类型
	//然后会让ch依次从s1的头到尾进行遍历
	//其实范围for的底层还是迭代器
	for (auto ch : s1)
	{
		cout << ch << ' ';
	}
}
void test6()
{
	string s1("hello world");
	s1.resize(5);
	cout << s1 << endl;;
	s1.resize(10, '!');
	cout << s1;
}
void test7()
{
	/*string s1("hello world");*/
	/*cout << s1[4] << ' ' << s1.at(4) << endl;
	cout << s1.back() << ' ' << s1.front() << endl;*/
	/*s1.append(s1, 5, 11);
	cout <<s1;*/

}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}