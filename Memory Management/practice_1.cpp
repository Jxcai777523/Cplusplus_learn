//对自定义类型进行操作

#include<iostream>
using namespace std;
class A
{
public:
	A(int a)
		: _a(a)
	{
		cout << "A(int a = 1)"<< endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* a = new A;
	delete a;
	A* a1 = new A(3);
	delete a1;
	A* a2 = new A[3](1, 2, 3);
	delete[] a2;
	return 0;
}
//#include<iostream>
//using namespace std;
//
//void Test()
//{
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p1 = (int*)malloc(sizeof(int) * 4);//开辟4个整形大小的空间
//	int* p2 = (int*)calloc(4, sizeof(int));//开辟4个整形大小的空间并将所有元素初始化为0
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);//在p2的基础上进行扩容，扩成10个整形的大小
//	// 这里需要free(p2)吗？
//	//很显然不需要，当我们free(p3)，那么p2的空间也被释放了
//	free(p1);
//	free(p3);
//}
//int main()
//{
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int* p1 = new int;//相当于（int*)malloc(sizeof(int));
//	int* p2 = new int(5);//将申请的变量初始化为5
//	int* p3 = new int[5](1, 2, 3, 4, 5);//申请了五个整形大小的空间，并依次进行初始化
//	int* p4 = new int[5](1, 2, 3);//剩下的初始化为0
//	delete p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//	return 0;
//}