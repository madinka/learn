// Передаем чертежи
// C++
#include <string>
#include <iostream>

// Third party
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

#include <gtest/gtest.h>

// App
#include "logger.h"
#include "logger_py.h"  // только для инициализации

using boost::python::object;
using boost::python::handle;
using boost::python::borrowed;
using boost::python::error_already_set;
using boost::shared_ptr;

// Third party
#include <gtest/gtest.h>

TEST(EmbLogger, Logger) {

  // Build - где-то
  std::string string_di("c++");
  shared_ptr<World> ptr_cc_object(new World(string_di));

  // Work:Task0
  { 
    Py_Initialize();
    try {
      init_hello_ext_module();
	    std::string file_name = "scripts/logger.py";

      // Подготовка к вызову
      object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
      boost::python::object global_namespace(main.attr("__dict__"));
      boost::python::exec_file(file_name.c_str(), global_namespace, global_namespace);

      // pass the reference to a_cxx_foo into python:
      // def work(...)
      object work = main.attr("work");
      work(ptr_cc_object);  // Появляется копия shared_ptr<Foo> ptr_cc

    } catch (error_already_set) {
      PyErr_Print();
    }

    Py_Finalize();
  }

  // Work::Task1
  ptr_cc_object->greet();
}