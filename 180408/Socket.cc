 ///
 /// @file    Socket.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 21:16:10
 ///
 
#include "Socket.h"
#include "SocketUtil.h"
#include "InetAddress.h"

namespace wd
{

Socket::Socket(int sockfd)
:sockfd_(sockfd)
{}

Socket::Socket()
:sockfd_(createSocketFd())
{}

Socket::~Socket()
{
	::close(sockfd_);
}

void Socket::nonblock()
{
	setNonblock(sockfd_);
}

void Socket::shutdownWrite()
{
	if(::shutdown(sockfd_,SHUT_WR) == -1)
	{
		perror("shutdown write error!");
	}
}

InetAddress Socket::getPeerAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd,(struct sockaddr *)&addr,&len) == -1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}


}
