 ///
 /// @file    textQuery.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-30 22:36:23
 ///
 
#include <iostream>
using std::cout;
using std::endl;


TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back()text;
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
