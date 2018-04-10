///
/// @file    impl.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-03-01 15:50:37
///
#ifndef __PUBLIC_H_INCLUDE__
#define __PUBLIC_H_INCLUDE__
class Book
{
	public:
		Book();
		~Book();
		void print();

	private:
	class BookImpl;
	BookImpl *pimpl;
};

#endif
