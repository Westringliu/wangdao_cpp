 ///
 /// @file    figure2.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-01 17:17:52
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

void calcArea(Figure * fig)
{
	fig->display();
	cout << fig->area() << endl;
}

class Rectangle
:public Figure
{
public:
	Rectangle(double length,double width)
	:_length(length)
	,_width(width)
	{}

	void display()
	{	cout << "Rectangle's area:";	}	

	double area()
	{
		return _length * _width;
	}

private:
	double _length;
	double _width;
};

class Circle
:public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display()
	{	cout << "circle's area: ";	}

	double area()
	{
		return PI * _radius * _radius;
	}

private:
	double _radius;
	const static double PI;
};
const double Circle::PI = 3.14159;

class Triangle
:public Figure
{
public:
	Triangle(double a, double b,double c)
	:_a(a)
	,_b(b)
	,_c(c)
	{}

	void display()
	{
		cout << "Triangle's area: ";
	}

	double area()
	{
		double p = (_a + _b + _c) / 2.0;
		return sqrt((p - _a)*(p - _b)*(p-_c)*p);
	}

private:
	double _a;
	double _b;
	double _c;
};

class Factory
{
public:
	virtual Figure * createFigure() = 0;
};

class RectangleFactory
: public Factory
{
public:
	Figure * createFigure()
	{
		return new Rectangle(4,5); 
	}
};

class CircleFactory
: public Factory
{
public:
	Figure * createFigure()
	{
		return new Circle(10);
	}
};

class TriangleFactory
:public Factory
{
public:
	Figure * createFigure()
	{
		return new Triangle(3,4,5);
	}
};

int main(void)
{
	Rectangle rectangle(3,4);

	std::unique_ptr<Factory> pRectangleFactory(new RectangleFactory);
	std::unique_ptr<Factory> pCircleFactory(new CircleFactory);
	std::unique_ptr<Factory> pTriangleFactory(new TriangleFactory);

	std::unique_ptr<Figure> pRectangle(pRectangleFactory->createFigure());
	std::unique_ptr<Figure> pCircle(pCircleFactory->createFigure());
	std::unique_ptr<Figure> pTriangle(pTriangleFactory->createFigure());

	calcArea(pRectangle.get());
	calcArea(pCircle.get());
	calcArea(pTriangle.get());

	return 0;
}


