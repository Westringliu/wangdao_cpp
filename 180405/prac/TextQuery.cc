 ///
 /// @file    TextQuery.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-05 15:47:42
 ///

#include "TextQuery.h"
#include "QueryResult.h"
#include "make_plural.h"
#include <stdio.h>
#include <sstream>
using std::istringstream;

TextQuery::TextQuery(ifstream & is)
: file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto & lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string & sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought,nodata,file);
	else
		return QueryResult(sought,loc->second,file);
}

ostream & print(ostream & os,const QueryResult & qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(),"time","s") << endl;

	for(auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;
	 return os;
}


