#include "stateclock.h"

#include <iostream>

using namespace std;

enum MyClock::mode{
		DisplayingTime_, SettingHours_,SettingMinutes_
	};
void MyClock::ShowTime() {
	cout.width(2); cout << hour_ << " ";
	cout.width(2); cout << minute_ << " ";
	cout.width(2); cout << second_ << " ";
	cout << '\r';
}
void MyClock::reset() {
	behavior_=DisplayingTime_;
	hour_=0;
	minute_=0;
	second_=0;
}
void MyClock::ChangeMode() {
	behavior_=mode((behavior_ +1)%3);
}
void MyClock::increment(){
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
void MyClock::tick(){
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

