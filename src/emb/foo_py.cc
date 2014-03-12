#include "foo_py.h"

BOOST_PYTHON_MODULE(hello)  // => inithello()
{
  boost::python::class_<Foo, boost::shared_ptr<Foo>>("Foo")
    .def("doSomething", &Foo::doSomething)
  ;
}

// Для инициализации
void init_hello_module() {
  inithello();
}