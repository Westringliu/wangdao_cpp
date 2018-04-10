#include "Mylog.h"

int test0(void)
{
	Mylog::getInstance()->info("this is an info message");
	Mylog::getInstance()->error("this is an error message");
	Mylog::getInstance()->warn("this is a warn message");
	Mylog::getInstance()->debug("this is a debug message");

	return 0;
}

void test1(void)
{
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __FUNCTION__ << endl;
	cout << __func__ << endl;
}

void test2(void)
{
	logInfo(prefix("this is an info message"));
	logError(prefix("this is an info message"));
	logWarn(prefix("this is an info message"));
	logDebug(prefix("this is an info message"));
}

void test3(void)
{
	LogInfo("this is an info message");
	LogError("this is an info message");
	LogWarn("this is an info message");
	LogDebug("this is an info message");
}

int main(void)
{
//	test1();
		//test2();
			test3();
				return 0;
			}
	
