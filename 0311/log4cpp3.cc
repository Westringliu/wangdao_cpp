 ///
 /// @file    log4cpp3.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 23:20:25
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	//destination
	log4cpp::Appender *ostreamAppender = new log4cpp::OstreamAppender("cout",&cout);
	log4cpp::Appender *fileAppender = new log4cpp::FileAppender("FileAppender","wtr");
	//Layout
	log4cpp::PatternLayout *ptnLyt = new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt);
	
	log4cpp::PatternLayout *ptnLyt2 = new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt2);

	//put
	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.addAppender(ostreamAppender);
	root.addAppender(fileAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.warn("this is a warn message");
	root.error("this is an error message");
	root.info("this is a info message");
	return 0;
}
