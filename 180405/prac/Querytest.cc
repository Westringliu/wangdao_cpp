///
/// @file    Querytest.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-04-05 16:26:05
///

#include "TextQuery.h"
#include "QueryResult.h"
#include "make_plural.h"
int main(int argc,char **argv)
{
	if(argc != 2)
		cout << "error args!" << endl;

	ifstream ifs;
	ifs.open(argv[1]);
	TextQuery tq = TextQuery(ifs); 
	do {
		string sought;
		// find all the occurrences of the requested string
		// define synonym for the line_no set 
		std::cin >> sought; 
		const QueryResult results = tq.query(sought);
		// report no matches
		print(cout, results) << endl;
	} while (true);  // loop indefinitely; the exit is inside the loop
	return 0;
}
