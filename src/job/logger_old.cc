
#include <boost/python.hpp>

using namespace boost::python;

// ����������
//class Logger


// ����������
//int Logger::

// ������������
//MODULE...

char const* greet()
{
return "hello, world!!!!!!!";
}

struct World
{
void set(std::string msg) { this->msg = msg; }
std::string greet() { return msg; }
std::string msg;
};




BOOST_PYTHON_MODULE(hello_ext)
{
def("greet", greet);
class_<World>("World")
  .def("greet", &World::greet)
  .def("set", &World::set)
  ;

}