 ///
 /// @file    log4cpp2.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 23:11:32
 ///
 
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::Appender *ostreamAppender = new log4cpp::OstreamAppender("cout",&cout);

	log4cpp::PatternLayout *ptnLyt = new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt);

	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.setAppender(ostreamAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.warn("this is a warn message");
	root.error("this is a error message");
	root.info("this is a info message");

	return 0;

}
