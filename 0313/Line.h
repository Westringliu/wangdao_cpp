 ///
 /// @file    Line.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 17:48:16
 ///

#ifndef __WD_LINE_H__
#define __WD_LINE_H__

class Line
{
public:
	Line(int,int,int,int);
	~Line();

	void printLine() const;
private:
	class LineImpl;
	LineImpl *_pImpl;
};

#endif
