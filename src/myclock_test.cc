#include "myclock.h"

// C

// C++
#include <iostream>

// Third party
#include <gtest/gtest.h>

// App

TEST(Myclock, None){
  MyClock a;
  a.ClockSet(10,59,30);
  for (int i=0; i< 1000; i++) {
	  a.tick();
	  a.Display();
  }
}
