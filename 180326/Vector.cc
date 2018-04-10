 ///
 /// @file    Vector.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 20:52:55
 ///

#include <memory>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
	typedef T * iterator;

	Vector();
	~Vector();

	void push_back(const T & value);
	void pop_back();

	T * begin()
	{
		return _start;
	}

	T * end()
	{
		return _finish;
	}

	int size() const;
	int capacity() const;

private:
	void reallocate();
private:
	static std::allocator<T> _alloc;

	T * _start;
	T * _finish;
	T * _end_of_storage;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
: _start(0)
,_finish(0)
,_end_of_storage(0)
{}

template <typename T>
Vector<T>::~Vector()
{
	if(size() > 0)
	{
		while(_start != _finish)
			_alloc.destroy(--_finish);
		_alloc.deallocate(_start,capacity());
	}
}

template <typename T>
int Vector<T>::size() const
{
	return _finish - _start;
}

template <typename T>
int Vector<T>::capacity() const
{
	return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity())
	{
		reallocate();
	}
	_alloc.construct(_finish,value);
	++_finish;
}

template <typename T>
void Vector<T>::pop_back()
{
	_alloc.destroy(--_finish);	
}

template <typename T>
void Vector<T>::reallocate()
{
	int oldCapacity = capacity();
	int newCapacity = (oldCapacity == 0 ? 1 : 2 * oldCapacity);

	T * newStart = _alloc.allocate(newCapacity);

	if(_start)
	{
		std::uninitialized_copy(_start,_finish,newStart);
		while(_start != _finish)
			_alloc.destroy(--_finish);

		_alloc.deallocate(_start,oldCapacity);
	}
	_start = newStart;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

void displayCapacity(Vector<int> & vec)
{
	cout << "vec's size = " << vec.size() <<endl;
	cout << "vec's capa = " << vec.capacity() <<endl;
}

int main(void)
{
	Vector<int> vec;
	vec.push_back(1);
	displayCapacity(vec);
	vec.push_back(2);
	displayCapacity(vec);
	vec.push_back(3);
	displayCapacity(vec);
	vec.push_back(4);
	displayCapacity(vec);
	vec.push_back(5);
	displayCapacity(vec);
	vec.push_back(6);
	displayCapacity(vec);
	
	Vector<int>::iterator it = vec.begin();
	for(;it != vec.end(); ++it)
	{
		cout << *it << endl; 
	}

}
