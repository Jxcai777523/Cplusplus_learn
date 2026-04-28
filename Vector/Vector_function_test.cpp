#include<iostream>
#include<vector>
using namespace std;
void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 1);
	vector<int> v3(v2.begin()+2, v2.end()-1);
	vector<int> v4(v3);
}
void test_vector2()
{
	vector<int> v1(10,1);
	vector<int>::iterator it = v1.begin();
	int i = 0;
	while (it != v1.end())
	{
		*it = i++;
		cout << *it << ' ';
		it++;
	}
}
void test_vector3()
{
	vector<int> v1;
	cout << v1.capacity() << endl;
	for (int i = 0;i < 100;i++)
	{
		v1.push_back(i);
		if (v1.size() == v1.capacity())
		{
			cout << v1.capacity() << endl;
		}
	}
}
//reserve和resize
void test_vector4()
{
	//在vs编译器中reserve以及resize的逻辑都是大的扩容
	vector<int> v1(10,1);
	cout << v1.capacity() << endl;
	v1.reserve(100);//扩容
	cout << v1.capacity() << endl;
	v1.shrink_to_fit();
	//根据size对capacity进行调整
	cout << v1.size() << ' ' << v1.capacity() << endl;

	vector<int> v2(10, 1);
	cout << v2.capacity() << endl;
	v2.reserve(5);//不扩容
	cout << v2.capacity() << endl;

	vector<int> v3(10, 1);
	cout << v3.capacity() << endl;
	v3.resize(100);//扩容
	cout << v3.capacity() << endl;

	vector<int> v4(10, 1);
	cout << v4.capacity() << endl;
	v4.resize(5);//不扩容,但是改变size
	cout << v4.capacity() << endl;
	cout << v4.size() << endl;
}
void test_vector5()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	cout << v[0] << ' ' << v.at(9) << endl;
	cout << v.front() << ' ' << v.back() << endl;
	int* start = v.data();//返回向量内部用于存储其自有元素的内存数组的直接指针
	cout << *start+5;
}
void test_vector6()
{
	vector<int> v;
	for (int i = 0;i < 5;i++)
	{
		v.push_back(i);
	}
	for (auto it : v)
	{
		cout << it << ' ';
	}
	cout << endl;
	v.pop_back();
	for (auto it : v)
	{
		cout << it << ' ';
	}
}
void test_vector7()
{
	vector<int> v;
	for (int i = 0;i < 5;i++)
	{
		v.push_back(i);
	}
	auto it = v.begin();
	v.insert(it + 2, 5);
	for (auto it : v)
	{
		cout << it << ' ';
	}
	cout << endl;
	v.insert(it + 2, 4, 8);
	for (auto it : v)
	{
		cout << it << ' ';
	}
	cout << endl;
}
void test_vector8()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	auto it = v.begin();
	v.erase(it + 9);
	for (auto it : v)
	{
		cout << it << ' ';
	}
	cout << endl;
	v.erase(it + 2, it + 6);
	for (auto it : v)
	{
		cout << it << ' ';
	}
	v.clear();
}
//展示一下二维数组
void test_vector9()
{
	/*vector<int> v1(5, 1);
	vector<vector<int>> v2(4, v1);
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			cout << v2[i][j] << ' ';
		}
		cout << endl;
	}*/

	vector<int> v(5, 7);
	vector <vector<int>> vv(7, v);
	for (int i = 0;i < vv.size();i++)
	{
		for (int j = 0;j < vv[i].size();j++)//可能每行的列数不同
		{
			cout << vv[i][j] << ' ';
		}
		cout << endl;
	}
}
void test_vector10()
{
	vector<int> v(5, 1);
	cout << v.at(6);

}
int main()
{	
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5(); 
	//test_vector6();
	/*test_vector7();*/
	/*test_vector8();*/
	//test_vector9();
	test_vector9();
	return 0;
}