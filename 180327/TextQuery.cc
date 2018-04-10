 ///
 /// @file    TextQuery.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-28 09:49:30
 ///

#include <ctype.h>

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::string;
using std::istringstream;

class TextQuery
{
public:
	TextQuery(){}

	void readFile(const string & filename);
	void query(const string & word);
private:
	vector<string> _lines;
	map<string,set<int>> _word2line;
	map<string,int> _dict;

};

void TextQuery::readFile(const string & filename)
{
	std::ifstream ifs(filename);
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
	}
	string line;
	int cnt = 0;

	while(getline(ifs,line))
	{
		_lines.push_back(line);

		for(size_t idx = 0;idx != line.size(); ++idx)
		{
			if(!isalpha(line[idx]))
			{
				line[idx] = ' ';
			}
			if(isupper(line[idx]))
			{
				line[idx] += 32;
			}
		}
		
		std::stringstream iss(line);
		string word;
		while(iss >> word)
		{
			++_dict[word];

			_word2line[word].insert(cnt);
		}
		++cnt;
	}
}

void TextQuery::query(const string & word)
{
	set<int> & numbers = _word2line[word];
	if(numbers.size() > 0)
	{
		cout << word << " occures " << _dict[word] << " times.\n";
		for(auto it = numbers.begin();it != numbers.end(); ++it)
		{
			cout << " (line " << (*it) + 1 << ") " << _lines[*it] << endl;
		}
	}else{
		cout << word << " not found!" << endl;
	}
}

int main(void)
{
	TextQuery tq;
	tq.readFile("china_daily.txt");

	string word;
	while(std::cin >> word)
	{
		tq.query(word);
	}
	return 0;
}
