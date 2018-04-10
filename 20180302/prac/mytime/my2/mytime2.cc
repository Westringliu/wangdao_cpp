 ///
 /// @file    mytime0.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 16:11:18
 ///

#include "mytime2.h"
#include <iostream>
using std::cout;
using std::endl;

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h,int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h,int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time &t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time &t) const
{
	Time diff;
	int tot1,tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * t.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(double mult,const Time & t)
{
	return t * mult;
}

void Time::Show() const
{
	cout << hours << "hours, " << minutes << " minutes";
}

void operator<<(std::ostream &os ,const Time &t)
{
	os << t.hours << "hours, " << t.minutes << "minutes";
}
