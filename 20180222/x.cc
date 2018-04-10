///
/// @file    x.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-22 23:33:04
///

#include <iostream>
using std::cout;
using std::endl;

class X
{
	public:
		X(int ix)
			: _iy(ix)
			  , _ix(_iy)
	{
		cout << "X(int) " << endl;
	}

		void print()
		{
			cout << "(" << _ix
				<< "," << _iy
				<< ")" << endl;
		}
	private:
		int _iy;
		int _ix;
};

int main(void)
{
	X x(2);
	x.print();

}
