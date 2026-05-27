#define _CRT_SECURE_NO_WARNINGS
//#include<vector>
//using namespace std;
//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& x1, const T& x2)
//	{
//		return x1 < x2;
//	}
//};
//template<class T>
//class Greater
//{
//public:
//	bool operator()(const T& x1, const T& x2)
//	{
//		return x1 > x2;
//	}
//};
//template<class Compare>
//void BubbleSort(int* a, int n, Compare com)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int flag = 0;
//		for (int j = 1; j < n - i; j++)
//		{
//			//if (a[j - 1] > a[j])
//			if (com(a[j], a[j - 1]))
//			{
//				swap(a[j - 1], a[j]);
//				flag = 1;
//			}
//		}
//
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	Less<int> less;
//	Greater<int> greater;
//
//	int a[] = { 2,6,1,8,4,9,7 };
//	BubbleSort(a, 7, less);
//	BubbleSort(a, 7, greater);
//
//	//传匿名对象
//	BubbleSort(a, 7, Less<int>());
//	BubbleSort(a, 7, Greater<int>());
//
//	return 0;
//}

//#include<queue>
//#include<iostream>
//using namespace std;
//void test()
//{
//	priority_queue<int> pq;
//	for (int i = 0;i < 5;i++)
//	{
//		pq.push(i);
//	}
//	if (pq.empty())
//	{
//		cout << "空" << endl;
//	}
//	const int size = pq.size();
//	for (int i = 0;i < size;i++)
//	{
//		cout << pq.top() << ' ';
//		pq.pop();
//	}
//
//}
//int main()
//{
//	test();
//	return 0;
//}