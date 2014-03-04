#include <components/config.h>
// http://stackoverflow.com/questions/3761391/boostpython-python-list-to-stdvector
// http://stackoverflow.com/questions/6157409/stdvector-to-boostpythonlist

// C++
#include <vector>
#include <string>

// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

// App
#include "protocols/protocols.h"
#include "protocols/protocols_py.h"

using std::vector;
using std::string;
namespace py = boost::python;
using namespace boost::python;
using boost::shared_ptr;

// App
using protocols::IProtocol;
using protocols::ProtocolsLayerImpl;
using protocols::ReadResult;

static string portName = "COM7";

//extern void __cdecl initprotocols_module(void);

TEST(Std, Protocols) {
  Py_Initialize();
  try {
    init_protocols_py_module();  // !!!

    //shared_ptr<IProtocol> old_protocol(new IProtocol());
    //old_protocol->resetLayerParameters(portName);

    //shared_ptr<ProtocolsLayerImpl> ptr_cc_object(new ProtocolsLayerImpl(old_protocol));

    object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
    boost::python::object global_namespace(main.attr("__dict__"));
    boost::python::exec_file("../scripts/protocols_test.py", global_namespace, global_namespace);

    // pass the reference to a_cxx_foo into python:
    //object setup_function = main.attr("setup");
    //setup_function(ptr_cc_object);

    // now run the python 'main' function
    object run_func = main.attr("create_on_python_side");
    run_func();
  } catch (error_already_set& e) {
    Py_Finalize();
    PyErr_Print();
    throw e;
  }

  Py_Finalize();
}
