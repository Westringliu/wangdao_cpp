 ///
 /// @file    Mylog.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 21:19:49
 ///
#ifndef __WD_MYLOG_H__
#define __WD_MYLOG_H__

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Mylog
{
public:
	static Mylog *getInstance();

	static void destroy();

	void info(const char *msg);
	void error(const char *msg);
	void warn(const char *msg);
	void debug(const char *msg);
private:
	Mylog();
	~Mylog();
private:
	log4cpp::Category &_cat;
	static Mylog *_pInstance;
};

void logInfo(const char *msg);
void logError(const char *msg);
void logWarn(const char *msg);
void logDebug(const char *msg);

inline string int2str(int num)
{
	std::ostringstream oss;
	oss << num;
	return oss.str();
}

#define prefix(msg) string("[").append(__FILE__).\
					append(":").append(__func__).\
					append(":").append(int2str(__LINE__)).\
					append("]").append(msg).c_str()

#define LogInfo(msg) logInfo(prefix(msg));
#define LogError(msg) logError(prefix(msg));
#define LogWarn(msg) logWarn(prefix(msg));
#define LogDebug(msg) logDebug(prefix(msg));

#endif
