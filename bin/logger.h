#pragma once
#define BOOST_NO_EXCEPTIONS
// C++
#include <iostream>

// Third party
#include <boost/shared_ptr.hpp>
//using boost::shared_ptr;  // BAD

char const* greet();

class Hello {
  public:
  Hello(std::string msg) : msg_(msg) {}
  std::string say() {
    return msg_;
  }
  std::string msg_;
};

class World {
public:
  World(std::string msg): msg(msg) {} // added constructor
  void set(std::string msg) { this->msg = msg; }
  std::string greet() { return msg; }
  std::string msg;
};

class Talker {
public:
  Talker(boost::shared_ptr<::Hello> hallo) : hallo_(hallo) { }
  std::string say() {
  return hallo_->say();
  }
private:
  boost::shared_ptr<Hello> hallo_;
};



