#include"Date.h"
bool Date::Checkdate()
{
	if (_month > 12 || _month<1 || _day>Getmonth_day(_year, _month) || _day < 1)
		return false;
	return true;
}
Date::Date(int year, int month, int day)//分离时，声明给缺省值
{
	_day = day;
	_month = month;
	_year = year;
}
void Date::Print()
{
	cout << _year << '/' << _month << '/' << _day << endl;
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > Getmonth_day(_year, _month))
	{
		_day -= Getmonth_day(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	/*tmp._day += day;
	while (tmp._day > Getmonth_day(tmp._year, tmp._month))
	{
		tmp._day -= Getmonth_day(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}*/
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)//因为数组中的0
		{
			_month = 12;
			_year--;
		}
		_day += Getmonth_day(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//this<date
bool Date::operator<(const Date& date)
{
	//把所有true的情况列举出来，那么其他的就是false
	if (_year < date._year)
	{
		return true;
	}
	else if (_year == date._year && _month < date._month)
	{
		return true;
	}
	else if (_year == date._year && _month < date._month && _day < date._day)
	{
		return true;
	}
	else
		return false;
}
bool Date::operator==(const Date& date)
{
	return _year == date._year && _month == date._month && _day == date._day;
}
bool Date::operator!=(const Date& date)
{
	return !(*this == date);
}
bool Date::operator>(const Date& date)
{
	return !(*this < date || *this == date);
}
bool Date::operator<=(const Date& date)
{
	return !(*this > date);
}
bool Date::operator>=(const Date& date)
{
	return !(*this < date);
}
int Date::operator-(Date& date)
{
	Date min = date;
	Date max = *this;
	int count_day = 0;
	if (*this < date)
	{
		min = *this;
		max = date;
	}
	while (min != max)
	{
		++min;
		++count_day;
	}
	return count_day;
}
//*this<<out
//void Date::operator<< (ostream& out)
//{
//	out << _year << "年" << _month << "月" << _day << "日" << endl;
//}
ostream& operator<<(ostream& out, const Date& date)
{
	out << date._year << '/' << date._month << '/' << date._day << endl;
	return out;
}
istream& operator>>(istream& in,  Date& date)
{
	in >> date._year >> date._month >> date._day;
	return in;
}
