// Выполнение встоенным интерпритатором Python
// 
// https://github.com/zaqwes8811/in-the-vicinity-cc/wiki/Cpp-Code-Deamonds
//
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

TEST(EmbPy, RunFromString) {
  Py_Initialize();
  try {
    PyRun_SimpleString(
      "a_foo = None\n"
      "\n"
      "def setup(a_foo_from_cxx):\n"
      "  print 'setup called with', a_foo_from_cxx\n"
      "  global a_foo\n"
      "  a_foo = a_foo_from_cxx\n"
      "\n"
      "def run():\n"
      "  a_foo.doSomething()\n"
      "\n"
      "print 'main module loaded'\n"
    );

    boost::shared_ptr<Foo> ptr_cc_object = boost::make_shared<Foo>("c++");


    init_hello_module();
    object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));

    // pass the reference to a_cxx_foo into python:
    object setup_function = main.attr("setup");
    setup_function(ptr_cc_object);

    // now run the python 'main' function
    object run_func = main.attr("run");
    run_func();
  } catch (error_already_set) {
    PyErr_Print();
  }

  Py_Finalize();
}

TEST(EmbPy, RunFromFile) {
  // Build - где-то
  std::string string_di = "c++";
  boost::shared_ptr<Foo> ptr_cc_object = boost::make_shared<Foo>(string_di);

  // Do it()
  { 
    Py_Initialize();
    try {
      init_hello_module();
	    std::string file_name = "scripts/emb_template_test.py";

      // Подготовка к вызову
      object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
      boost::python::object global_namespace(main.attr("__dict__"));
      boost::python::exec_file(file_name.c_str(), global_namespace, global_namespace);

      // pass the reference to a_cxx_foo into python:
      // def work(...)
      object work = main.attr("work");
      work(ptr_cc_object);
    } catch (error_already_set) {
      PyErr_Print();
    }

    Py_Finalize();
  }
}
