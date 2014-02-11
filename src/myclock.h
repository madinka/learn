#pragma once  // защита от повторного включения - только для Visual Studio
#ifndef MY_CLOCK_H_
#define MY_CLOCK_H_

//using namespace std;  // BAD!
class MyClock {
public:
  MyClock() {
  
  }
  // MyClock a(1, 2, 1);
  MyClock(int h, int m, int s) {
    hour_ = h;
    min_ = m;
    sec_ = s;
  }
  
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
