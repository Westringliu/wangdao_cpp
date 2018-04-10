 ///
 /// @file    stonewt.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 20:49:10
 ///

#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;//fractional pounds
	double pounds;//entire weight in pounds
public:
	Stonewt(double lbs);//pounds
	Stonewt(int stn,double lbs);//stone,pounds
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;

	operator int() const;
	operator double() const;
};

#endif
