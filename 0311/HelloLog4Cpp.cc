 ///
 /// @file    HelloLog4Cpp.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 21:21:29
 ///
 
#include <iostream>
#include "log4cpp/Category.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::OstreamAppender *osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new log4cpp::BasicLayout());
	log4cpp::Category &root = log4cpp::Category::getRoot();

	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("ERROR message");
	root.warn("WARN message");
	log4cpp::Category::shutdown();

	return 0;
}
