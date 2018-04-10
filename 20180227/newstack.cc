#include <iostream>

using namespace std;

class Test{
	public:
		Test(){
			cout << "Test 构造" << endl;
			str = new char[2];
		}
		~Test(){
			cout << "Test 析构" << endl;
			delete [] str;
		}
	private:
		char * str;
};

int main(int argc, char* argv[])
{
	char buf[100];  // 栈变量
	Test *p = new(buf) Test(); // Test()产生的临时变量用于初始化 指定内存地址

	//p->~Test(); // 一定要主动调用析构函数，避免内存泄漏。 而且调用必须在 buf 生命周期内调用才有效。

	// buf 指向的栈内存并不需要程序员主动释放。
	// 栈变量过了生命周期会自动释放内存
	// 其实栈内存的释放也不叫内存释放，只是栈顶指针移动，如果该块栈内存没有被其他程序刷新，那么该栈内存的值依然不变。


	char * buf2 = new char[100];
	Test * p2 = new(buf2) Test();

	p2->~Test(); // 切记，主动调用析构函数

	delete [] buf2; // 堆内存需要主动释放

	return 0;
}
