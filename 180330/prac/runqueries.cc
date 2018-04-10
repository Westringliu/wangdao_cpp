 ///
 /// @file    runqueries.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-30 22:19:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void runQueries(ifstream & infile)
{
	TextQuery tq(infile);

	while(true)
	{
		cout << "enter or q:";
		string s;

		if(!(cin >> s) || s == "q") break;

		print(cout ,tq.query(s)) << endl;
	}
}
