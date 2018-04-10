 ///
 /// @file    TcpServer.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 17:15:21
 ///
 
#ifndef __WD_TCPSERVER_H__
#define __WD_TCPSERVER_H__

#include "Acceptor.h"
#include "EpollPoller.h"
#include <string>
using std::string;

namespace wd
{

class TcpServer
{
public:
	typedef EpollCallback TcpServerCallback;
	TcpServer(const string & ip,unsigned short port);
	TcpServer(unsigned short port);

	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback cb);
	void setMessageCallback(TcpServerCallback cb);
	void setCloseCallback(TcpServerCallback cb);

private:
	Acceptor acceptor_;
	EpollPoller poller_;

	TcpServerCallback connectionCallback_;
	TcpServerCallback messageCallback_;
	TcpServerCallback closeCallback_;
};
}

#endif

