 ///
 /// @file    QueryResult.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-05 15:59:20
 ///

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "TextQuery.h"

class QueryResult
{
	friend ostream & print(ostream &,const QueryResult &);
public:
	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f)
	:sought(s),lines(p),file(f)
	{}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;

};

#endif
