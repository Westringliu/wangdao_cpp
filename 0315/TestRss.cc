//
/// @file    TestRss.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-05 11:15:37
///

#include "tinyxml2.h"

#include <boost/regex.hpp>

#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::fstream;

using namespace tinyxml2;


void test(void)
{
	string filename = "pagelib.dat";
	ofstream ofs(filename,std::ios::app);
	if(!ofs.good())
	{
		cout << "failed to open " << filename << "\n";
		return;
	}
	XMLDocument doc;
	doc.LoadFile("qrs.xml");

	int ret = doc.ErrorID();
	cout << "ret = " << ret << endl;

	XMLElement * proot = doc.FirstChildElement("rss");

	XMLElement * pitem = proot->FirstChildElement("channel")->FirstChildElement("item");

	do
	{

		XMLElement * ptitle = pitem->FirstChildElement("title");
		XMLElement * plink = pitem->FirstChildElement("link");
		XMLElement * pcontent = pitem->FirstChildElement("content:encoded");

		string title(ptitle->GetText());
		string link(plink->GetText());
		string content(pcontent->GetText());

		ofs << "title:" << title << endl;
		ofs << "link: " << link << endl;
		//cout << "content:" << content << endl;


		boost::regex expr("<.+?>");

		ofs << boost::regex_replace(content, expr, string("")) << endl;

	}while((pitem = pitem->NextSiblingElement("item")) != NULL);

}


int main(void)
{
	test();

	return 0;
}

