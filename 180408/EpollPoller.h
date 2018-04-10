 ///
 /// @file    EpollPoller.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 16:39:08
 ///
 
#ifndef __WD_EPOLLPOLLER_H
#define __WD_EPOLLPOLLER_H

#include <Noncopyable.h>
#include <TcpConnection.h>

#include <sys/epoll.h>
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <functional>

namespace wd
{

class Acceptor;
class EpollPoller : Noncopyable
{
public:
	typedef TcpConnection::TcpConnectionCallback EpollCallback;
	typedef std::function<void()> Functor;

	EpollPoller(Acceptor & acceptor);
	~EpollPoller();

	void loop();
	void unloop();
	void doPendingFunctors();

	void setConnectionCallback(EpollPoller cb);
	void setMessageCallback(EpollPoller cb);
	void setCloseCallback(EpollPoller cb);

private:
	void waitEpollfd();
	void handleConnection();
	void handleMessage(int peerfd);

private:
	Acceptor & acceptor_;
	int epollfd_;
	int listenfd_;
	bool isLooping_;

	typedef vector<struct epoll_event> EventList;
	EventList eventsList_;

	typedef map<int,TcpConnectionPtr> ConnectionMap;
	ConnectionMap connMap_;

	EpollCallback onConnectionCb_;
	EpollCallback onMessageCb_;
	EpollCallback onCloseCb_;
};
}

#endif
