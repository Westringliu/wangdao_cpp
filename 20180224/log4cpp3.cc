 ///
 /// @file    log4cpp1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-24 14:46:26
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
	//Appender代表日志输出目的地
	log4cpp::Appender *ostreamAppender=new log4cpp::OstreamAppender("cout",&cout);
	log4cpp::Appender *fileAppender=new log4cpp::FileAppender("fileAppender","wangdao.log");

	//PatternLayout设置日志的布局
	log4cpp::PatternLayout *ptnLyt=new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt);

	log4cpp::PatternLayout *ptnLyt2=new log4cpp::PatternLayout();
	ptnLyt2->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt2);
	
	//Category执行日志的输出
	log4cpp::Category&root=log4cpp::Category::getRoot();
	root.setAppender(ostreamAppender);
	root.addAppender(fileAppender);

	root.setPriority(log4cpp::Priority::DEBUG);

	//当优先级的值越小代表级别越高
	//当只有一条日志的优先级大与等于Category的优先级时该日志才会被记录

	root.warn("warn");
	root.error("error");
	root.info("info");

	log4cpp::Category::shutdown();

	return 0;
}
