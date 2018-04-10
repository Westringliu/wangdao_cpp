 ///
 /// @file    sequence1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-16 10:31:09
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

int vectortest(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1};
	vector<int> vecInt(arr,arr + 18);
	vector<int>::const_iterator cit = vecInt.begin();
	for(; cit != vecInt.end();++cit)
	{
		cout << *cit << "-";
	}
	cout << endl;

	cout << "sizeof(vector) = " << sizeof(vecInt) << endl;

	vecInt.push_back(1);

	auto it = vecInt.begin();
	++it;
	vecInt.insert(it,20);
	vecInt.insert(it,3,30);
	vecInt.insert(it,arr,arr + 3);



	it = vecInt.end();
	--it;
	for(size_t idx = 0;idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << " ";
	}
	cout << endl;

	vecInt.erase(it);
	it = vecInt.begin();
	++it;
	vecInt.erase(it,it + 7);
	cout << "sizeof(vecInt) = " << sizeof(vecInt) << endl;

	cout << "vecInt's size: " << vecInt.size() << endl;
	cout << "vecInt's capa: " << vecInt.capacity() << endl;

	vecInt.shrink_to_fit();
	cout << "after shrink_to_fit(): " << endl;
	cout << "vecInt's size: " << vecInt.size() << endl;
	cout  << "vecInt's capa: " << vecInt.capacity() << endl;
	for(auto &elem : vecInt)
	{
		cout << elem << ",";
	}
	cout << endl;
	
	vecInt.clear();
	cout << "after clear(): " << endl;
	cout << "vecInt's size: " << vecInt.size() << endl;
	cout  << "vecInt's capa: " << vecInt.capacity() << endl;
	
	vecInt.shrink_to_fit();
	cout << "after shrink_to_fit(): " << endl;
	cout << "vecInt's size: " << vecInt.size() << endl;
	cout  << "vecInt's capa: " << vecInt.capacity() << endl;

	return 0;
}

void dequetest(void)
{
	deque<int> deqInt = {1,2,3,4,5,6,7,8,9};
	deque<int>::const_iterator cit = deqInt.begin();
	for(;cit != deqInt.end(); ++ cit)
	{
		cout << *cit << " ";
	}
	cout << endl;

	deqInt.push_back(1);
	deqInt.push_front(10);

	auto it = deqInt.end();
	--it;

	for(auto &elem : deqInt)
	{
		cout << elem << ",";
	}
	cout << endl;
	deqInt.erase(it);
	it = deqInt.begin();
	++it;
	deqInt.erase(it,it + 3);
	for(size_t idx = 0;idx != deqInt.size();++idx)
	{
		cout << deqInt[idx] << "->";
	}
	cout << endl;
	deqInt.clear();

	return;
}

void listtest(void)
{
	list<int> liInt = {1,2,3,4,5,6,7,8,9};
	int arr[] = {1,2,3,4,5,6,7,8,9};

	liInt.push_back(1);

	auto lit = liInt.begin();
	++lit;

	liInt.insert(lit,20);
	liInt.insert(lit,3,30);
	liInt.insert(lit,arr,arr + 3);
	lit = liInt.end();
	--lit;

	list<int>::const_iterator cit = liInt.begin();
	for(;cit != liInt.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;

	liInt.erase(lit);
	lit = liInt.begin();
	++lit;
	liInt.erase(lit,--liInt.end());


	liInt.clear();
	cout << "after clear: " << endl;
	for(auto &elem : liInt)
	{
		cout << elem << endl;
	}
	cout << endl;
	return;
}
	
int main(void)
{
	//vectortest();
//	dequetest();
	listtest();
	return 0;
}
