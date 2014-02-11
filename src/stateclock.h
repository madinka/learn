#pragma once  // защита от повторного включения - только для Visual Studio
#ifndef MY_CLOCK_H_
#define MY_CLOCK_H_
#include <iostream>
using namespace std;
class MyClock {
public:
	void reset();
	void ChangeMode();
	void increment();
	void tick();
	void ShowTime();
private:
	enum mode;
	mode behavior_;
	int hour_; 
	int minute_; 
	int second_;
};



#endif  // MY_CLOCK_H_