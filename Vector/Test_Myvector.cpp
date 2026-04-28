#include"Vector.h"

using namespace mine;
void test1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.size() << ' ' << v.capacity() << endl;
	v.reserve(10);cout << v.size() << ' ' << v.capacity() << endl;
}
void test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << v[3] << endl;
	v.pop_back();
	for (auto it : v)
	{
		cout << it << ' ';
		it++;
	}
}
void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.resize(4);
	for (auto it : v)
	{
		cout << it << ' ';
		it++;
	}
	cout << endl;
	v.resize(10, 1);
	for (auto it : v)
	{
		cout << it << ' ';
		it++;
	}
	cout << endl;
}
void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto it : v)
	{
		cout << it << ' ';
		it++;
	}
	cout << endl;
	v.erase(v.end());
	for (auto it : v)
	{
		cout << it << ' ';
		it++;
	}
	v.clear();

	for (auto it : v)
	{
		cout << it << ' ' <<  endl;;
		it++;
	}
}
void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	mine::print_vector(v);
}
void test6()
{
	vector<string> v;
	std::string s1("hello");
	std::string s2(" world");
	v.push_back(s1);
	v.push_back(s2);
	mine::print_vector(v);
}
void test7()
{
	vector<int> v(5, 1);
	vector<int> v1 = v;
	mine::print_vector(v1);
}
//int main()
//{
//	//test2();
//	//test4();
//	test4();
//}
