#include"string.h"
using namespace mine;
//测试构造函数功能
namespace mine
{
	void test1()
	{
		string s1;
		std::cout << s1.c_str() << std::endl;
		string s2("hello ");
		std::cout << s2.c_str() << std::endl;
		string s3 = s2;
		std::cout << s3.c_str() << std::endl;
		string s4 = "hello world";
		std::cout << s4.c_str() << std::endl;
		s1 = "hello world";
		std::cout << s1.c_str() << std::endl;
		s1 = s2;
		std::cout << s1.c_str() << std::endl;
	}
	void test2()
	{
		string s1("hello world");
		s1[5] = '!';
		for (auto ch : s1)
		{
			std::cout << ch << ' ';
			ch++;
		}
		size_t len = s1.size();
		size_t capacity = s1.capacity();
	}
	void test3()
	{
		string s1 = "hello world";
		string s2("!!!!");
		s1 += s2;
		std::cout << s1.c_str() << std::endl;
		s1.insert(2, "---");
		std::cout << s1.c_str() << std::endl;
	}
	void test4()
	{
		string s("test.cpp.zip");
		size_t pos = s.find('.');
		string suffix = s.substr(pos);
		cout << suffix.c_str() <<endl;
	}
	void test5()
	{
		string s1;
		cin >> s1;
		cout << s1;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	/*mine::test4();*/
	test5();
	return 0;
}