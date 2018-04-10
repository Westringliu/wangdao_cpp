 ///
 /// @file    Point.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 13:45:47
 ///
#ifndef _Point_h
#define _Point_h
class Point
{
public:
	void initPoint(float x = 0,float y = 0)
	{
		this ->x = x;this ->y = y;
	}

	void move(float offX,float offY)
	{
		x += offX;
		y += offY;
	}

	float getX() const
	{
		return x;
	}
	float getY() const
	{
		return y;
	}

private:
	float x,y;
};

#endif
