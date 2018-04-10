 ///
 /// @file    TcpConnection.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 16:54:53
 ///
 
#ifndef _WD_TCPCONNECTION_H
#define _WD_TCPCONNECTION_H

#include "Noncopyable.h"
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"

#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
#include <function>

namespace wd
{
	
class TcpConnection;
typedef shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection : Noncopyable,
	public std::enable_shared_from_this<TcpConnection>
{
public:
	typedef std::function<void(const TcpConnectionPtr &)> TcpConnectionCallback;
	TcpConnection(int sockfd);
	~TcpConnection();

	string receive();
	void send(const string & msg);
	void shutdown();

	string toString();

	void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();

private:
	Socket sockfd_;
	SocketIO sockIO_;
	const InetAddress localAddr_;
	const InetAddress peerAddr_;
	bool isShutdownWrite_;
	TcpConnectionCallback onConnectionCb_;
	TcpConnectionCallback onMessageCb_;
	TcpConnectionCallback onCloseCb_;

};
}

#endif
