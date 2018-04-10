 ///
 /// @file    log4cpp1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-24 14:46:26
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	//Appender代表日志输出目的地
	log4cpp::Appender*ostreamAppender=new log4cpp::OstreamAppender("cout",&cout);

	ostreamAppender->setLayout(new log4cpp::BasicLayout());


	log4cpp::Category&root=log4cpp::Category::getRoot();
	root.setAppender(ostreamAppender);
	root.setPriority(log4cpp::Priority::ERROR);


	root.warn("warn");
	root.error("error");
	root.info("info");

	return 0;
}
