// di - dependency injections

#include "design/preamplifiers_hieracrhy.h"

// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python.hpp>
#include <boost/python/register_ptr_to_python.hpp>

using boost::shared_ptr;
using boost::python::object;
using boost::python::handle;
using boost::python::borrowed;
using boost::python::error_already_set;
using boost::python::register_ptr_to_python;
using boost::python::class_;
using boost::python::call_method;
using boost::python::def;
using boost::python::no_init;
using boost::python::wrapper;
using boost::python::init;

BOOST_PYTHON_MODULE(preampl)
{
  boost::python::class_<PreamplifierImplFake,
    boost::shared_ptr<PreamplifierImplFake>>("PreamplifierImplFake")
    .def("SetChannel", &PreamplifierImplFake::SetChannel)
  ;
}

BOOST_PYTHON_MODULE(preampl_wrapper)
{
  boost::python::class_<
          PreamplifierWrapper, boost::shared_ptr<PreamplifierWrapper>>(
            "PreamplifierImplFake", init<shared_ptr<Preamplifier>>())
    .def("SetChannel", &PreamplifierWrapper::SetChannel)
  ;
}


TEST(DI, ErrorUsige) {

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
      "  #a_foo.SetChannel(6)\n"
      "  pass#a_foo.SetChannel(6)\n"
      "\n"
      "print 'main module loaded'\n"
    );

    // Not work...
    boost::shared_ptr<Preamplifier> ptr_cc_object(new PreamplifierImplFake());

    initpreampl();
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

TEST(DI, BeeSo) {

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
      "  a_foo.SetChannel(6)\n"
      "  pass#a_foo.SetChannel(6)\n"
      "\n"
      "print 'main module loaded'\n"
    );

    // Not work...
    shared_ptr<Preamplifier> fake(new PreamplifierImplFake);
    boost::shared_ptr<PreamplifierWrapper> ptr_cc_object(
        new PreamplifierWrapper(fake));

    initpreampl_wrapper();
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


