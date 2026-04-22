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

int main()
{
	test_vector2();
	return 0;
}