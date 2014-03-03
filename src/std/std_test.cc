// http://stackoverflow.com/questions/3761391/boostpython-python-list-to-stdvector
// http://stackoverflow.com/questions/6157409/stdvector-to-boostpythonlist

// C++
#include <vector>

// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using std::vector;
namespace py = boost::python;
using namespace boost::python;

template< typename T >
inline
std::vector< T > to_std_vector( const py::object& iterable ) {
    return std::vector< T >( py::stl_input_iterator< T >( iterable ),
                             py::stl_input_iterator< T >( ) );
}

template<class T>
py::list std_vector_to_py_list(const std::vector<T>& v) {
    py::object get_iter = py::iterator<std::vector<T> >();
    py::object iter = get_iter(v);
    py::list l(iter);
    return l;
}

// C++ code
class MyClass {
public:
  vector<unsigned char> myFuncGet() {
      return vector<unsigned char>();
  }
  void myFuncSet(const vector<unsigned char>& list) {
    printf("runned!!\n");
  }
};


BOOST_PYTHON_MODULE(mymodule)
{
    class_<vector<unsigned char>>("MyListClass")
        .def(vector_indexing_suite<vector<unsigned char>>() );


    //class_<MyClass>("MyClass")
    //    .def("myFuncGet", &MyClass::myFuncGet)
    //    .def("myFuncSet", &MyClass::myFuncSet)
    //    ;

    class_<MyClass, boost::shared_ptr<MyClass>>("MyClassShared")
        .def("myFuncGet", &MyClass::myFuncGet)
        .def("myFuncSet", &MyClass::myFuncSet)
        ;
}


TEST(Std, Vector) {
  Py_Initialize();
  try {
    initmymodule();  // !!!
    boost::shared_ptr<MyClass> ptr_cc_object = boost::make_shared<MyClass>();

    object main = object(handle<>(borrowed(PyImport_AddModule("__main__"))));
    boost::python::object global_namespace(main.attr("__dict__"));
    boost::python::exec_file("../scripts/std_test.py", global_namespace, global_namespace);

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

