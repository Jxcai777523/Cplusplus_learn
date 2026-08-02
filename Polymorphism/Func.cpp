#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
#include <iostream>
using namespace std;

//class Person {
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "买票-打折" << endl; }
//};
//
//void Func(Person* ptr)
//{
//    // 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//    // 但是跟ptr没关系，而是由ptr指向的对象决定的。
//    ptr->BuyTicket();
//}
//
//int main()
//{
//    Person ps;
//    Student st;
//
//    Func(&ps);
//    Func(&st);
//
//    return 0;
//}


//class Animal
//{
//public:
//    virtual void talk() const
//    {
//    }
//};
//
//class Dog : public Animal
//{
//public:
//    virtual void talk() const
//    {
//        std::cout << "汪汪" << std::endl;
//    }
//};
//
//class Cat : public Animal
//{
//public:
//    virtual void talk() const
//    {
//        std::cout << "(>^ω^<)喵" << std::endl;
//    }
//};
//
//void letsHear(const Animal& animal)
//{
//    animal.talk();
//}
//
//int main()
//{
//    Cat cat;
//    Dog dog;
//    letsHear(cat);
//    letsHear(dog);
//    return 0;
//}

//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//class Student : public Person {
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "买票-打折" << endl;
//		return nullptr;
//	}
//};
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//class B : public A {
//public:
//	~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//protected:
//	int* _p = new int[10];
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下⾯的delete对象调⽤析构函数，才能
////构成多态，才能保证p1和p2指向的对象正确的调⽤析构函数。
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//	delete p1;
//	delete p2;
//	return 0;
//}
//class Car 
//{
//public:
//    virtual void Dirve()
//    {
//    }
//};
//
//class Benz :public Car 
//{
//public:
//    virtual void Drive() override 
//    { 
//        cout << "Benz-舒适" << endl; 
//    }
//};
//
//int main()
//{
//    return 0;
//}
//class Car
//{
//public:
//    virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//    virtual void Drive() 
//    { 
//        cout << "Benz-舒适" << endl; 
//    }
//};
//
//int main()
//{
//    return 0;
//}
//class Car
//{
//public:
//    virtual void Drive() = 0; //这里有纯虚函数那么该类就是抽象类
//};
//
//class Benz : public Car
//{
//public:
//    virtual void Drive()
//    {
//        cout << "Benz-舒适" << endl;
//    }
//};
//
//class BMW : public Car
//{
//public:
//    virtual void Drive()
//    {
//        cout << "BMW-操控" << endl;
//    }
//};
//
//int main()
//{
//    // 编译报错：error C2259: “Car”: 无法实例化抽象类
//    Car car;
//
//    Car* pBenz = new Benz;
//    pBenz->Drive();
//
//    Car* pBMW = new BMW;
//    pBMW->Drive();
//
//    return 0;
//}
//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Func1()" << endl;
//    }
//protected:
//    int _b = 1;
//    char _ch = 'x';
//};
//
//int main()
//{
//    Base b;
//    cout << sizeof(b) << endl;
//
//    return 0;
//}
class Person 
{
public:
    virtual void BuyTicket() 
    { 
        cout << "买票-全价" << endl; 
    }
private:
    string _name;
};

class Student : public Person 
{
public:
    virtual void BuyTicket() 
    { 
        cout << "买票-打折" << endl; 
    }
private:
    string _id;
};

class Soldier : public Person {
public:
    virtual void BuyTicket() { cout << "买票-优先" << endl; }
private:
    string _codename;
};

void Func(Person* ptr)
{
    // 这⾥可以看到虽然都是Person指针Ptr在调⽤BuyTicket
    // 但是跟ptr没关系，⽽是由ptr指向的对象决定的。
    ptr->BuyTicket();
}

int main()
{
    // 其次多态不仅仅发⽣在派⽣类对象之间，多个派⽣类继承基类，重写虚函数后
    // 多态也会发⽣在多个派⽣类之间。
    Person ps;
    Student st;
    Soldier sr;
    Func(&ps);
    Func(&st);
    Func(&sr);
    return 0;
}