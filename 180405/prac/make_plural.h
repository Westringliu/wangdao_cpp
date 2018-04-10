///
/// @file    make_plural.h
/// @author  westring(1364643962@qq.com)
/// @date    2018-04-05 16:23:46
///

#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

//return the plural version of word if ctr is greater than 1
inline string make_plural(size_t ctr, const string &word,const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

#endif
