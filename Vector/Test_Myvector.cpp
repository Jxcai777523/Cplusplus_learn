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
	int a = int();
	vector<int> v = vector<int>();
}
int main()
{
	//test2();
	test3();


}