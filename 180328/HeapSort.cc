 ///
 /// @file    HeapSort.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-28 17:38:47
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <typename T,typename Compare = std::less<T>>
class HeapSort
{
public:
	HeapSort(const vector<T> & array)
	:_array(array)
	{}

	void heapAdjust(int parent,int size);
	void sort();
	void print();
private:
	vector<T> _array;
};

template <typename T,typename Compare>
void HeapSort<T,Compare>::heapAdjust(int parent,int size)
{
	T temp = _array[parent];
	int child = parent * 2 + 1;

	Compare compare;

	while(child < size)
	{
		if(child + 1 < size && compare(_array[child],_array[child + 1]))
			++child;

		if(compare(temp,_array[child]))
		{
			_array[parent] = _array[child];

			parent = child;
			child = parent * 2 + 1;
		}else
			break;
	}
	_array[parent] = temp;
}

template <typename T,typename Compare>
void HeapSort<T,Compare>::sort()
{
	for(int idx = _array.size() / 2 - 1;idx >= 0; --idx)
	{
		heapAdjust(idx,_array.size());
	}

	for(int idx = _array.size() - 1;idx >= 0; --idx)
	{
		std::swap(_array[0],_array[idx]);
		heapAdjust(0,idx);
	}
}

template <typename T,typename Compare>
void HeapSort<T,Compare>::print()
{
	typedef typename std::vector<T>::reverse_iterator reverse_iterator;//typename用于指定类型，typedef用于宏替换 

	reverse_iterator rit;
	for(rit = _array.rbegin();rit != _array.rend(); ++rit)
	{
		cout << * rit << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> numbers{3,1,5,2,7,6,4};
	HeapSort<int> hs(numbers);
	hs.sort();
	hs.print();

	return 0;
}
