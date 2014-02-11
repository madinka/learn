#include "stateclock.h"

#include <iostream>

using namespace std;

enum MyStateClock::mode{
		DisplayingTime_, SettingHours_,SettingMinutes_
	};
void MyStateClock::ShowTime() {
	cout.width(2); cout << hour_ << " ";
	cout.width(2); cout << minute_ << " ";
	cout.width(2); cout << second_ << " ";
	cout << '\r';
}
void MyStateClock::reset() {
	behavior_=DisplayingTime_;
	hour_=0;
	minute_=0;
	second_=0;
}
void MyStateClock::ChangeMode() {
	behavior_=mode((behavior_ +1)%3);
}
void MyStateClock::increment(){
	switch(behavior_) {
		case DisplayingTime_:
			break;
		case SettingHours_:
			hour_=(hour_+1)%24;
			break;
		case SettingMinutes_:
			minute_=(minute_+1)%60;
			break;
	}
}
void MyStateClock::tick(){
	switch(behavior_) {
		case DisplayingTime_:
			if(++second_==60) {
				second_=0;
				if (++minute_==60) {
					minute_=0;
					hour_=(hour_+1)%24;
				}
			}
			break;
		case SettingHours_:
			break;
		case SettingMinutes_:
			break;
	}
}

