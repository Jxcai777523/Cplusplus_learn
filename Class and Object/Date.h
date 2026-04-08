#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in,  Date& date);
public:

	bool Checkdate();
	Date(int year = 2000, int month = 1, int day = 1);
	void Print();
	int Getmonth_day(int year, int month)//默认内联函数，频繁调用的短小函数不会建立栈帧
	{
		static int days[] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		return days[month];
	}
	bool operator<(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
	bool operator>(const Date& date);
	bool operator<=(const Date& date);
	bool operator>=(const Date& date);
	//计算某一时间过了多少天之后的时间
	Date& operator+=(int day);
	Date operator+(int day);
	//计算某一时间前多少天的时间
	Date& operator-=(int day);
	Date operator-(int day);

	Date operator++(int);//后置++
	Date& operator++();//前置++

	Date operator--(int);//后置--
	Date& operator--();//前置--
	//计算两个时间相差多少天
	int operator-(Date& date);
	//如果我们把<< >>写成类成员函数
	/*void operator<<(ostream& out);*/
private:
	int _year;
	int _month;
	int _day;
};
