 ///
 /// @file    TextQuery.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-06 11:39:35
 ///
 
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::map;
#include <fstream>
using std::ifstream;
#include "QueryResult.h"

class QueryResult;

class TextQuery
{
public:
	typedef vector<string>::size_type line_no;
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
	void display_map();

private:
	shared_ptr<vector<string>> file;
	map<string,shared_ptr<set<line_no>>> wm;

	static string cleanup_str(const string &);
};

#endif

