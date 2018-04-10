 ///
 /// @file    TcpConnection.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 20:22:37
 ///
 
#include "TcpConnection.h"

#include <string.h>
using std::string;
#include <stdio.h>

namespace wd
{

TcpConnection::TcpConnection(int sockfd)
: sockfd_(sockfd)
, sockIO_(sockfd)
, localAddr_(wd::Socket::getLocalAddr(sockfd))
, peerAddr_(wd::Socket::getPeerAddr(sockfd))
, isShutdownWrite_(false)
{
	sockfd_.nonblock();
}

TcpConnection::~TcpConnection()
{
	if(~isShutdownWrite_)
	{
		isShutdownWrite_ = true;
		shutdown();
	}
	printf("~TcpConnection()\n");
}

string TcpConnection::receive()
{
	char buf[65536];
	memset(buf,0,sizeof(buf));
	size_t ret = sockIO_.readline(buf,sizeof(buf));
	if(ret == 0)
	{
		return string();
	}
	else
		return string(buf);
}
	
void TcpConnection::send(const string & msg)
{
	sockIO_.writen(msg.c_str(),msg.size());
}

void TcpConnection::shutdown()
{
	if(!isShutdownWrite_)
		sockfd_.shutdownWrite();
	isShutdownWrite_ = true;
}

string TcpConnection::toString()
{
	char str[100];
	snprintf(str,sizeof(str),"%s:%d -> %s:%d",
			localAddr_.ip().c_str(),
			localAddr_.port(),
			peerAddr_.ip().c_str(),
			peerAddr_.port());

	return string(str);
}

void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
	onConnectionCb_ = cb;
}

void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
	onMessageCb_ = cb;
}

void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
	onCloseCb_ = cb;
}

void TcpConnection::handleConnectionCallback()
{
	if(onConnectionCb_)
		onConnectionCb_(shared_from_this());
}

void TcpConnection::handleMessageCallback()
{
	if(onMessageCb_)
		onMessageCb_(shared_from_this());
}

void TcpConnection::handleCloseCallback()
{
	if(onCloseCb_)
		onCloseCb_(shared_from_this());
}

}
