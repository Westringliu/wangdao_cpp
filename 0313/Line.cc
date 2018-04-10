 ///
 /// @file    Line.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 17:50:44
 ///

#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;
//LineImpl is inside the Line,func in Line base on LineImpl,LineImpl base on Point
class Line::LineImpl
{
	class Point
	{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout << "Point()" << endl;
		}

		void print() const
		{
			cout << "(" << _ix
				<< "," << _iy
				<< ")";
		}
	private:
		int _ix;
		int _iy;
	};

public:
	LineImpl(int x1,int y1,int x2,int y2)
	:_p1(x1,y1)
	,_p2(x2,y2)
	{
		cout << "LineImpl()" << endl;
	}

	void printLine() const
	{
		_p1.print();
		cout << "--->";
		_p2.print();
		cout << endl;
	}

	~LineImpl()
	{
		cout << "~LineImpl()" << endl;
	}
private:
	Point _p1;
	Point _p2;
};

Line::Line(int x1,int y1,int x2,int y2)
//pImpl create by new,so it must be a pointer
:_pImpl(new LineImpl(x1,y1,x2,y2))//this pointer is init by class LineImpl
{
	cout << "Line(int,int,int,int)" << endl;
}

void Line::printLine() const
{
	//_pImpl is a pointer,must use ->
	_pImpl->printLine();
}

Line::~Line()
{
	cout << "~Line()" << endl;
	delete _pImpl;
}

int main(void)
{
	Line line(4,5,6,7);
	line.printLine();

	return 0;
}
