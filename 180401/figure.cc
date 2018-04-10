 ///
 /// @file    figure.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-01 16:00:10
 ///
 
#include <math.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Figure
{
public:
	virtual double area() = 0;
	virtual void display() = 0;
};

void calaArea(Figure * fig)
{
	fig->display();
	cout << fig->area() << endl;
}

class Rectangle
: public Figure
{
public:
	Rectangle(double length,double width)
	: _length(length)
	, _width(width)
	{}

	void display()
	{	cout << "Rectangle's area: ";	}

	double area()
	{	return _length * _width;	}

private:
	double _length;
	double _width;
};

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display()
	{
		cout << "circle's area: ";
	}

	double area()
	{
		return PI * _radius * _radius;
	}

private:
	double _radius;
	const static double PI;
};
const double Circle::PI = 3.1415926535897932384626;

class Triangle
: public Figure
{
public:
	Triangle(double a,double b,double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void display()
	{	cout << "Triangle's area: ";	}

	double area()
	{
		double p = (_a + _b + _c) / 2.0;
		return sqrt((p - _a) * (p - _b) * (p - _c) * p);
	}

private:
	double _a;
	double _b;
	double _c;
};

class FigureFactory
{
public:
	static Figure * getRectangle()
	{
		return new Rectangle(4,5);
	}

	static Figure * getCircle()
	{
		return new Circle(10);
	}

	static Figure * getTriangle()
	{
		return new Triangle(3,4,5);
	}
};

int main(void)
{
	std::unique_ptr<Figure> pRectangle(FigureFactory::getRectangle());
	std::unique_ptr<Figure> pCircle(FigureFactory::getCircle());
	std::unique_ptr<Figure> pTriangle(FigureFactory::getTriangle());

	calaArea(pRectangle.get());
	calaArea(pCircle.get());
	calaArea(pTriangle.get());

	return 0;
}
