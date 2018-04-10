 ///
 /// @file    templateSingleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-05 20:45:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point()" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point &rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream &os,const Point &rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()
		{
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	static T *getInstance();

private:
	Singleton(){cout << "Singleton()" << endl;}
	~Singleton(){cout << "~Singleton" << endl;}

private:
	static T *_pInstance;
	static AutoRelease _autoRelease;
};

template <typename T>
T *Singleton<T>::_pInstance = NULL;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

template <typename T>
T *Singleton<T>::getInstance()
{
	if(NULL == _pInstance)
	{
		_autoRelease;
		_pInstance = new T;
	}

	return 0;
}

int main(void)
{
	Point * pt1 = Singleton<Point>::getInstance();
	Point * pt2 = Singleton<Point>::getInstance();

	cout << "pt1 = " << pt1 << endl;
	cout << "pt2 = " << pt2 << endl;

	return 0;
}
