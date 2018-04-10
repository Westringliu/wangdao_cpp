 ///
 /// @file    SocketIO.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 17:33:44
 ///
 
#ifndef _WD_SOCKTEIO_H
#define _WD_SOCKTEIO_H

#include <stdio.h>

namespace wd
{
class SocketIO
{
public:
	SocketIO(int sockfd);

	size_t readn(char * buf,size_t count);
	size_t writen(const char * buf,size_t count);
	size_t readline(char * buf,size_t max_len);

private:
	size_t recv_peek(char * buf,size_t count);

private:
	int sockfd_;
};
}

#endif
