 ///
 /// @file    Acceptor.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 17:22:15
 ///
 
#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace wd
{
	
class Acceptor
{
public:
	Acceptor(int listenfd,const Inetaddress & addr);

	void ready();
	int accept();

	int fd() const{		return listenSock_.fd();	}
private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();

private:
	Socket listenSock_;
	Inetaddress addr_;
};
}

#endif
