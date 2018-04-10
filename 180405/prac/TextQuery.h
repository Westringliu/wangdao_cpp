 ///
 /// @file    TextQuery.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-05 15:37:04
 ///

#ifndef TextQuery_H
#define TextQuery_H

#include <string>
using std::string;
#include <map>
using std::map;
#include <set>
using std::set;
#include <vector>
using std::vector;
#include <istream>
using std::ifstream;
#include <ostream>
using std::ostream;
#include <fstream>
using std::ifstream;
#include <memory>
using std::shared_ptr;

using line_no = vector<string>::size_type; 

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream &);
	QueryResult query(const string &) const;

private:
	shared_ptr<vector<string>> file;
	map<string,shared_ptr<set<line_no>>> wm;
};

#endif
