#pragma once  // защита от повторного включения - только для Visual Studio
#ifndef MY_CLOCK_H_
#define MY_CLOCK_H_

//using namespace std;  // BAD!
class MyClock {
public:
	void Display();
	void ClockSet(int h, int m, int s);
	void tick();
private:
	void sw_();
	int hour_; 
	int min_; 
	int sec_;
};
#endif  // MY_CLOCK_H_
