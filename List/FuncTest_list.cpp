#include<iostream>
#include<list>
#include<vector>
using namespace std;
//底层是我们以前学过的带头双向循环链表
void list_test1()//构造函数
{	
	list<int> l1;//无参构造
	list<int> l2(10, 1);//10个1
	vector<int> v1(10, 1);
	list<int> l3(v1.begin(), v1.end());//迭代器构造
	list<int> l4(l3);//拷贝构造
	//遍历打印
	//这里我们要说一下，list的迭代器是双向迭代器，支持++ 以及--，但是不支持+ -，因为链表在空间上不支持进行连续的跳跃
	//多间隔节之间是无法建立直接关系的，而连续节点之间存在直接关联 
	list<int>::iterator it = l3.begin();
	while (it != l3.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;
	for (auto it : l2)
	{
		cout << it << ' ';
	}
}
void list_test2()
{
	list<int> l1(5, 1);
	if (!l1.empty())
	{
		cout << l1.size();
	}
}
void list_test3()
{
	list<int> l1(5, 1);
	int i = 0;
	auto it = l1.begin();
	while (it != l1.end())
	{
		*it++ = i++;
	}
	cout << l1.front() << ' ' << l1.back();

}
void list_test4()
{
	list<int> l1;
	list<int> l2;
	l1.assign(5, 1);
	l2.assign(l1.begin(), l1.end());
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	for (auto it : l2)
	{
		cout << it << ' ';
	}
	//头插尾插 头删尾删

	l1.push_front(6);
	l1.push_back(7);

	l2.pop_front();
	l2.pop_back();
	cout << endl;
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	for (auto it : l2)
	{
		cout << it << ' ';
	}
}
void list_test5()
{
	list<int> l1;
	for (int i = 0;i < 5;i++)
	{
		l1.push_back(i);
	}
	//l1.insert(l1.begin() +3, 9);list的迭代器不支持跳跃
	//我们要实现上述功能只能先让迭代器一次一次移动，用循环到指定位置
	//insert是在指定位置之前插入
	l1.insert(++l1.begin(), 9);//可以只插入一个数，也可以插入多个相同的数
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.insert(++l1.begin(), 2, 7);
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	vector<int> v1;
	for (int i = 0;i < 5;i++)
	{
		v1.push_back(i);
	}
	l1.insert(++l1.begin(), v1.begin() + 1, v1.end() - 1);
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.erase(++l1.begin());
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.erase(++l1.begin(), --l1.end());
	for (auto it : l1)
	{
		cout << it << ' ';
	}
}
void list_test6()
{
	list<int> l1;
	for (int i = 0;i < 10;i++)
	{
		l1.push_back(i);
	}
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.resize(5, 5);//会进行缩小
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.resize(10, 6);//进行扩容，多出的部分补充为6
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	l1.clear();
}
void list_test7()
{
	list<int> l1;
	list<int> l2;
	for (int i = 0;i < 10;i++)
	{
		l2.push_back(i);
		l1.push_back(i + 10);
	}
	l1.splice(l1.begin(), l2);
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
	for (auto it : l2)//l2的已经全部剪切到l1了
	{
		cout << it << ' ';
	}
	cout << endl;
	//还有别的用法，可以只剪切一个元素或者利用迭代器剪切部分元素
	for (int i = 0;i < 6;i++)
	{
		l1.remove(i);
		l1.remove(i + 7);
	}
	l1.splice(l1.begin(), l2);
	for (auto it : l1)
	{
		cout << it << ' ';
	}
	cout << endl;
}
//int main()
//{
//	//list_test1();
//	//list_test2();
//	//list_test3();
//	//list_test4();
//	//list_test5();
//	//list_test6();
//	list_test7();
//	return 0;
//}