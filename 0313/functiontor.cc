///
/// @file    functiontor.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-03-13 16:27:20
///

#include <iostream>
using std::cout;
using std::endl;

template<class T>  
class Functor  
{  
	public:  
		enum Type{Plus,Sub};  
		Functor(Type t = Plus) :type(t){}  
		T operator()(T a, T b)  
		{  
			if (type == Plus) return a + b;  
			return a - b;  
		}  
	private:  
		Type type;  
};  
int main()  
{  
	//同时定义了一个加法器和一个减法器。  
	Functor<int> plus(Functor<int>::Plus);     
	Functor<int> sub(Functor<int>::Sub);  
	int a = 5, b = 3;  
	cout << plus(a, b) << endl;  
	cout << sub(a, b) << endl;  
	return 0;  
}  
