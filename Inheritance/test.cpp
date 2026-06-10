#include<iostream>
#include<string>
#include<vector>
using namespace std;
//class student
//{
//public:
//	void identity()
//	{
//		//……一些身份认证操作
//	}
//	void study()
//	{
//		//……学习
//	}
//private:
//	string _name = "peter"; // 姓名
//    string _address;        // 地址
//	string _tel;            // 电话
//	int _age = 18;          // 年龄
//
//	int _stuid;             // 学号
//};
//class teacher
//{
//public:
//	void identity()
//	{
//		//……一些认证操作
//	}
//	void teach()
//	{
//		//……一些教学操作
//	}
//
//private:
//	string _name = "张三"; // 姓名
//	string _address;        // 地址
//	string _tel;            // 电话
//	int _age = 18;          // 年龄
//
//	string _title;          // 职称
//};

//我们将重复的信息写成一个单独的类person
//class person
//{
//	//这里要设计成保护类型
//public:
//	void identity()
//	{
//		
//	}
//protected:
//	string _name = "peter"; // 姓名
//	string _address;        // 地址
//	string _tel;            // 电话
//	int _age = 18;          // 年龄
//};
//
//class student:public person
//{
//public:
//	void study()
//	{
//
//	}
//private:
//	int _stuid;             // 学号
//};
//
//class teacher :public person
//{
//public:
//	void teach()
//	{
//
//	}
//private:
//	string _title;          // 职称
//};

//class person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name;//姓名
//private:
//	int _age;//年龄
//};
//
////class student :public person
////class student :protected person
//class student :private person
//{
//protected:
//	int _stuid;   //学号
//};
//
//int main()
//{
//	student s;
//	s.Print();
//	return 0;
//}

//继承类模板

//namespace mine
//{
//	template<class T>
//	class stack :public std::vector<T>
//	{
//	public:
//		void push(const T& val)
//		{
//			vector<T>::push_back(val);
//		}
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//		bool empty() const
//		{
//			return vector<T>::empty();
//		}
//	};
//}
//int main()
//{
//	mine::stack<int> s;
//	s.push(1);
//	s.push(2);
//	return 0;
//}

//class person
//{
//protected:
//	string name;//姓名
//	string sex;//性别
//	int age;//年龄
//};
//
//class student :public person
//{
//public:
//	int _id;
//};
//
//int main()
//{
//	student s;
//	//子类的对象可以赋值给父类的对象
//	person p = s;
//	//子类的对象可以赋值给父类的引用 指针
//	person* pp = &s;
//	person& rp = s;
//	//父类不能给子类对象赋值
//	s = p;
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//    string _name = "小李子"; // 姓名
//    int _num = 111;    // 身份证号
//};
//
//class Student : public Person
//{
//public:
//    void Print()
//    {
//        cout << " 姓名:" << _name << endl;
//        cout << " 身份证号:" << Person::_num << endl;//我们需要指定类域
//        cout << " 学号:" << _num << endl;
//    }
//protected:
//    int _num = 999; // 学号
//};
//
//int main()
//{
//    Student s1;
//    s1.Print();
//    return 0;
//}

//class person
//{
//public:
//	person()
//	{
//		_name = "小蔡";
//	}
//	person(const person& p)
//	{
//		_name = p._name;
//	}
//protected:
//	std::string _name;//姓名
//};
//
//class student:public person
//{
//public:
//	student(int id=24346101)
//		: _num(id),
//		person()//我们这里调用的是父类的构造函数
//	{ }
//	student(const student& st)
//		: person(st),
//		_num(st._num)
//	{}
//	void print()
//	{
//		cout << "姓名：" << _name << endl;
//		cout << "学号：" << _num << endl;
//	}
//private:
//	int _num;//学号
//};
//
//int main()
//{
//	student s1(24336101);
//	student s2(s1);
//	s2.print();
//}

//class Person
//{
//public:
//    Person(const char* name = "peter")
//        : _name(name)
//    {
//        cout << "Person()" << endl;
//    }
//
//    Person(const Person& p)
//        : _name(p._name)
//    {
//        cout << "Person(const Person& p)" << endl;
//    }
//
//    Person& operator=(const Person& p)
//    {
//        cout << "Person operator=(const Person& p)" << endl;
//        if (this != &p)
//            _name = p._name;
//        return *this;
//    }
//
//    virtual ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//
//protected:
//    string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//    Student(const char* name, int num)
//        : Person(name)
//        , _num(num)
//    {
//        cout << "Student()" << endl;
//    }
//
//    Student(const Student& s)
//        : Person(s)
//        , _num(s._num)
//    {
//        cout << "Student(const Student& s)" << endl;
//    }
//
//    Student& operator=(const Student& s)
//    {
//        cout << "Student& operator= (const Student& s)" << endl;
//        if (this != &s)
//        {
//            // 构成隐藏，所以需要显示调用
//            Person::operator=(s);
//            _num = s._num;
//        }
//        return *this;
//    }
//
//    ~Student()
//    {
//        cout << "~Student()" << endl;//会自动调用父类的析构，我们可以不用手动写，如果要写也需要加virtual
//    }
//
//protected:
//    int _num; // 学号
//};
//
//int main()
//{
//    Student s1("jack", 18);
//    Student s2(s1);
//    Student s3("rose", 17);
//    s1 = s3;
//
//    return 0;
//}

// C++11的方法
//class Base final
//{
//public:
//    void func5()
//    {
//        cout << "Base::func5" << endl;
//    }
//protected:
//    int a = 1;
//
//};
//
//class Derive : public Base
//{
//    void func4() { cout << "Derive::func4" << endl; }
//protected:
//    int b = 2;
//};
//
//int main()
//{
//    Base b;
//    return 0;
//}

//class Student;
//class Person
//{
//public:
//    friend void Display(const Person& p, const Student& s);
//protected:
//    string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//    int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//    cout << p._name << endl;
//    cout << s._stuNum << endl;
//}
//
//int main()
//{
//    Person p;
//
//    Student s;
//    // 编译报错: error C2248: “Student::_stuNum”: 无法访问 protected 成员
//    // 解决方案: Display也变成Student 的友元即可
//
//    Display(p, s);
//
//    return 0;
//}

//class person
//{
//public:
//	string _name;
//	static int num;
//};
//int person::num = 0;
//class student :public person
//{
//protected:
//	string stuid;
//};
//
//int main()
//{
//	person p;
//	student s;
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	cout << &p.num << endl;
//	cout << &s.num << endl;
//}

class Person
{
public:
    string _name; // 姓名
};

class Student : virtual public Person
{
protected:
    int _num; // 学号
};

class Teacher : virtual public Person
{
protected:
    int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
    string _majorCourse; // 主修课程
};

int main()
{
    // 编译报错: error C2385: 对“_name”的访问不明确
    Assistant a;
    a._name = "peter";
    // 需要显示指定访问哪个基类的成员可以解决二义性问题，但是数据冗余问题无法解决
    a.Student::_name = "xxx";
    a.Teacher::_name = "yyy";
    return 0;
}