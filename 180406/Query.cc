 ///
 /// @file    Query.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-06 14:49:22
 ///
 
#include "Query.h"
#include "TextQuery.h"

#include <memory>
using std::shared_ptr;
#include <set>
using std::set;
#include <algorithm>
using std::set_intersection;
#include <iostream>
using std::ostream;
#include <cstddef>
using std::size_t;
#include <iterator>
using std::inserter;
#include <vector>
using std::vector;
#include <string>
using std::string;

QueryResult NotQuery::eval(const TextQuery & text) const
{
	QueryResult result = query.eval(text);

	shared_ptr<set<line_no>> ret_lines(new set<line_no>);

	QueryResult::line_it beg = result.begin(),end = result.end();

	vector<string>::size_type sz = result.get_file()->size();
	for(size_t n = 0;n != sz; ++n)
	{
		if(beg == end || *beg != n)
			ret_lines->insert(n);
		else if(beg != end)
			++beg;
	}
	return QueryResult(rep(),ret_lines,result.get_file());
}

QueryResult AndQuery::eval(const TextQuery & text) const
{
	QueryResult left = lhs.eval(text),right = rhs.eval(text);

	shared_ptr<set<line_no>> ret_lines(new set<line_no>);

	set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));

	return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult OrQuery::eval(const TextQuery & text) const
{
	QueryResult right = rhs.eval(text),left = lhs.eval(text);

	shared_ptr<set<line_no>> ret_lines(new set<line_no>(left.begin(),left.end()));

	ret_lines->insert(right.begin(),right.end());

	return QueryResult(rep(),ret_lines,left.get_file());
}
