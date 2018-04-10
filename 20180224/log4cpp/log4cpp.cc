///
/// @file    log4cpp1.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-24 14:46:26
///
#include "func.h"
using std::cout;
using std::endl;
using std::string;

class Mylog
{
	public:
		Mylog();
		~Mylog();
		void error(const char *msg);
		void warn(const char *msg);
		void info(const char *msg);
		void debug(const char *msg);
		void set_priority(const char *);

	private:
		log4cpp::PatternLayout *pLayout_cout_;
		log4cpp::PatternLayout *pLayout_file_;

		log4cpp::OstreamAppender *osAppender_;
		log4cpp::FileAppender *fileAppender_;

		log4cpp::Category &root_;

};

Mylog::Mylog():root_(log4cpp::Category::getInstance("infoCategory"))
{
	cout<<"Mylog()"<<endl;


	//PatternLayout设置日志的布局
	pLayout_cout_=new log4cpp::PatternLayout();
	pLayout_file_=new log4cpp::PatternLayout();

	//创建Appender并将Layout对象绑定
	osAppender_=new log4cpp::OstreamAppender("osAppender_", &std::cout);
	osAppender_->setLayout(pLayout_cout_);


	//Appender代表日志输出目的地
	fileAppender_=new log4cpp::FileAppender("fileAppender","wangdao.log");
	fileAppender_->setLayout(pLayout_file_);

	//当优先级的值越小代表级别越高
	//当只有一条日志的优先级大与等于Category的优先级时该日志才会被记录

	root_.addAppender(osAppender_);
	root_.addAppender(fileAppender_);

}

void Mylog::set_priority(const char *prioritylevel)
{
	if(prioritylevel=="DEBUG")
		root_.setPriority(log4cpp::Priority::DEBUG);
	else if(prioritylevel=="ERROR")
		root_.setPriority(log4cpp::Priority::ERROR);
	else if(prioritylevel=="WARN")
		root_.setPriority(log4cpp::Priority::WARN);
	else if(prioritylevel=="INFO")
		root_.setPriority(log4cpp::Priority::INFO);
	else
		root_.setPriority(801);
}

void Mylog::error(const char *msg)
{
	cout<<"error()"<<std::endl;
	root_.error(msg);
}

void Mylog::warn(const char *msg)
{
	cout<<"warn()"<<endl;
	root_.warn(msg);
}

void Mylog::info(const char *msg)
{
	cout<<"info()"<<endl;
	root_.info(msg);
}

void Mylog::debug(const char *msg)
{
	cout<<"debug()"<<endl;
	root_.debug(msg);
}

Mylog::~Mylog()
{
	cout<<"Mylog()"<<endl;
	log4cpp::Category::shutdown();
}

int main(int argc, char * argv[])
{
	const char * msg = "hello,world";
	const char * priority = "ERROR";
	Mylog mylog;
	mylog.set_priority(priority);
	mylog.error(msg);
	mylog.warn(msg);
	mylog.info(msg);
	mylog.debug(msg);

	return 0;
}

