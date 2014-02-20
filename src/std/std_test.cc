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

  }
};


BOOST_PYTHON_MODULE(mymodule)
{
    class_<vector<unsigned char>>("MyListClass")
        .def(vector_indexing_suite<vector<unsigned char>>() );

    class_<MyClass>("MyClass")
        .def("myFuncGet", &MyClass::myFuncGet)
        .def("myFuncSet", &MyClass::myFuncSet)
        ;
}


TEST(Std, Vector) {


}

