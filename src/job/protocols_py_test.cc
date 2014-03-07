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
  // Build
  //shared_ptr<IProtocol> old_protocol(new IProtocol());
  //old_protocol->resetLayerParameters(portName);
  //shared_ptr<ProtocolsLayerImpl> ptr_to_cc_obj(new ProtocolsLayerImpl(old_protocol));

  // Do it()
  { 
    // Python magic
    Py_Initialize();
    try {
      std::string script_name = "../scripts/protocols_test.py";
      init_protocols_py_module();  // !!! init_hello_...
      object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
      boost::python::object global_namespace(main.attr("__dict__"));
      boost::python::exec_file(script_name, global_namespace, global_namespace);

      // def work(...)
      // pass the reference to a_cxx_foo into python:
      //object work_function = main.attr("work");
      //work_function(ptr_to_cc_obj);
    } catch (error_already_set& e) {
      Py_Finalize();
      PyErr_Print();
      throw e;
    }

    Py_Finalize();
  }
}
