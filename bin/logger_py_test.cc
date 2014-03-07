// C++
#include <string>
#include <iostream>

// Third party
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python.hpp>

#include <gtest/gtest.h>

// App
#include "emb/foo.h"
#include "emb/foo_py.h"

using boost::python::object;
using boost::python::handle;
using boost::python::borrowed;
using boost::python::error_already_set;

// Third party
#include <gtest/gtest.h>

TEST(EmbLogger, Logger) {

  // Build - где-то
  //std::string string_di = "c++";
  //boost::shared_ptr<Foo> ptr_cc_object = boost::make_shared<Foo>(string_di);

  // Do it()
  { 
    Py_Initialize();
    try {
      //init_hello_ext_module();
	    std::string file_name = "scripts/glue.py";

      // Подготовка к вызову
      object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
      boost::python::object global_namespace(main.attr("__dict__"));
      boost::python::exec_file(file_name.c_str(), global_namespace, global_namespace);

      // pass the reference to a_cxx_foo into python:
      // def work(...)
      //object work = main.attr("work");
      //work(ptr_cc_object, ?);
    } catch (error_already_set) {
      PyErr_Print();
    }

    Py_Finalize();
  }
}