 ///
 /// @file    InetAddress.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 17:09:09
 ///
 
#ifndef _WD_INETADDRESS_H
#define _WD_INETADDRESS_H

#include <netinet/in.h>
#include <string>
using std::string;

namespace wdd
{

class InetAddress
{
public:
	InetAddress(short port);
	
	InetAddress(const char * pIp,short port);

	InetAddress(const struct sockaddr_in & addr);

	const struct sockaddr_in * getSockAddrPtr() const;
	string ip() const;
	unsigned short port() const;
private:
	struct sockaddr_in addr_;
};
}

#endif
