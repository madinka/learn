#include "clock.h"

// Third party
#include <gtest/gtest.h>

TEST(Clock, Hello) {
  myclock clock;
  clock.PrintHello();

  //
  clock.UpOutPower();
}