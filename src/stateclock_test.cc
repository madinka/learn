#include "stateclock.h"

// C

// C++
#include <iostream>

// Third party
#include <gtest/gtest.h>

// App

TEST(MyStateclock, None){
	MyStateClock my_state_clock;
	my_state_clock.reset();

	my_state_clock.ChangeMode();
	for (int i = 0; i < 6; i++)
		my_state_clock.increment();

	my_state_clock.ChangeMode();
	for (int i = 0; i < 30; i++)
		my_state_clock.increment();

	my_state_clock.ChangeMode();
	for (int i = 0; i < 1000; ++i) {
		my_state_clock.tick();
		my_state_clock.ShowTime();
	}
}
