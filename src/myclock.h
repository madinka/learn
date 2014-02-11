#pragma once  // защита от повторного включения - только для Visual Studio
#ifndef MY_CLOCK_H_
#define MY_CLOCK_H_

#include <iostream>
using namespace std;
class myclock {
public:
void disp();
void clockset (int h, int m, int s) {
  hour_=h; min_=m; sec_=s;
}
void tick() {
  if (sec_==59) {
    sec_=0; min_++;
  }
  else sec_++;
  if (min_=+60) {
    min_==0; hour_++;
  }
}
private:
void sw_() {
  cout.fill('0');
  cout.width(2);
};
int hour_; int min_; int sec_;
};

void myclock::disp(){
	sw_(); cout << hour_;
	cout << ':';
	sw_(); cout << min_;
	cout << ':';
	sw_(); cout << sec_;
	cout << '\r';
}

#endif  // MY_CLOCK_H_
