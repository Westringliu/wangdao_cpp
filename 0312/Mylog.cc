 ///
 /// @file    Mylog.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 20:37:37
 ///
 
#include "Mylog.h"

Mylog *Mylog::_pInstance = NULL;
	Mylog * Mylog::getInstance()//_pInstance is a pointer,so return a pointer
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Mylog();
		}
			return _pInstance;
	}

	void Mylog::destroy()
	{
		if(_pInstance != NULL)
			delete []_pInstance;
	}

	Mylog::Mylog()
	:_cat(log4cpp::Category::getRoot())
	{
		log4cpp::Appender *ostreamAppender = new log4cpp::OstreamAppender("cout",&cout);
		log4cpp::Appender *fileAppender = new log4cpp::FileAppender("fileAppender","wangdao.log");

		log4cpp::PatternLayout *ptnLyt = new log4cpp::PatternLayout();
		ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
		ostreamAppender->setLayout(ptnLyt);

		log4cpp::PatternLayout *ptnLyt2 = new log4cpp::PatternLayout();
		ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
		ostreamAppender->setLayout(ptnLyt2);

		log4cpp::Category &_cat = log4cpp::Category::getRoot();
		_cat.addAppender(ostreamAppender);
		_cat.addAppender(fileAppender);
		_cat.setPriority(log4cpp::Priority::DEBUG);
	}

Mylog::~Mylog()
{
	log4cpp::Category::shutdown();
}

void Mylog::info(const char * msg)
{
	_cat.info(msg);
}
void Mylog::error(const char * msg)
{
	_cat.error(msg);
}
void Mylog::warn(const char * msg)
{
	_cat.warn(msg);
}
void Mylog::debug(const char * msg)
{
	_cat.debug(msg);
}

void logInfo(const char *msg)
{
	Mylog::getInstance()->info(msg);
}
void logError(const char *msg)
{
	Mylog::getInstance()->error(msg);
}
void logWarn(const char *msg)
{
	Mylog::getInstance()->warn(msg);
}
void logDebug(const char *msg)
{
	Mylog::getInstance()->debug(msg);
}
