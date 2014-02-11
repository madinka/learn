#include "stateclock.h"

// C

// C++
#include <iostream>

// Third party
#include <gtest/gtest.h>

// App

TEST(Myclock, None){
	MyClock C;
	C.reset();
	C.ChangeMode();
	for (int i=0; i<6; i++)
		C.increment();
	C.ChangeMode();
	for (int i=0; i<30; i++)
		C.increment();
	C.ChangeMode();
	while (1) {
		C.tick();
		C.ShowTime();
	}
}
