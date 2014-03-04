
// C++
#include <iostream>

//
#include <boost/python.hpp>
using namespace boost::python;
using boost::shared_ptr;

// Объявление
//class Logger


// Реализация
//int Logger::

// Оборачивание
//MODULE...

char const* greet()
{
return "hello, world!";
}

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
  Talker(boost::shared_ptr<Hello> hallo) : hallo_(hallo) { }
  std::string say() {
  return hallo_->say();
  }
private:
  boost::shared_ptr<Hello> hallo_;
};


BOOST_PYTHON_MODULE(hello_ext)
{
  def("greet", greet)
    ;
  class_<World>("World", init<std::string>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    ;
    

  // WorldPtr
  class_<Hello, boost::shared_ptr<Hello> >("Hello", /*Основноый конструктор*/init< std::string >()) 
    .def("say", &Hello::say)
  ;
    
  class_<Talker, boost::shared_ptr<Talker> >("Talker", init<shared_ptr<Hello>>())
      .def("say", &Talker::say)
    ;
}

namespace boost
{

#ifdef BOOST_NO_EXCEPTIONS

void throw_exception(std::exception const & e) {
    throw e;
}; // user defined

#else

//[Not user defined --Dynguss]
template<class E> inline void throw_exception(E const & e)
{
    throw e;
}

#endif

} // namespace boost