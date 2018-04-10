///
/// @file    Computer2.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-02-22 11:21:57
///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(const char * brand, float price)
			//: _brand(brand) //浅拷贝
			: _brand(new char[strlen(brand) + 1]()) //深拷贝
			  , _price(price)
	{
		cout << "Computer(const char *,float)" << endl;
		strcpy(_brand, brand);
	}

		//就是用来做清理工作的
		~Computer()
		{
			cout << "~Computer()" << endl;
			delete [] _brand;
			_brand = NULL;
		}

		void print();

		void setBrand(const char * brand);

		void setPrice(float price);

	private:
		char * _brand;
		float _price;
};


void print()
{
	cout << "print()" << endl;
}

//在类之外实现成员函数
void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _price << endl;
}

void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}


//全局对象
Computer pc2("Thinkpad", 6666);

int main(void)
{
	char brand[] = "Xiaomi";

	Computer com(brand, 4999);//栈对象
	com.print();
	//com.~Computer();//不要显式调用析构函数

	cout<<"pc2 is"<<pc2._brand<<endl;

	Computer * p = new Computer("Mac", 10000);//堆对象
	p->print();
	delete p;//不可少

	return 0;
}
