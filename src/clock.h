// TODO: Директивы защиты от повторного включения
#pragma once

//#
class myclock {
 public:
   myclock() : min_(0) {
   
   }
  void PrintHello();

  void UpOutPower();

private:
  int min_;
};

class myclock2 : public myclock {
 public:
   myclock2() : min_(0) {
   
   }
   //void PrintHello() {};

  //void UpOutPower();

private:
  int min_;
};