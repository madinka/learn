#include "myclock.h"

#include <iostream>

using namespace std;

void MyClock::ClockSet(int h, int m, int s) {
  hour_=h; min_=m; sec_=s;
}

void MyClock::tick() {
  if (sec_==59) {
    sec_=0; 
    min_++;
  } else 
    sec_++;
  if (min_ =+ 60) {  // err
    min_ == 0;  // err 
    hour_++;
  }
}

void MyClock::sw_() {
  cout.fill('0');
  cout.width(2);
}

void MyClock::Display(){
	sw_(); cout << hour_;
	cout << ':';
	sw_(); cout << min_;
	cout << ':';
	sw_(); cout << sec_;
	cout << '\r';
}
