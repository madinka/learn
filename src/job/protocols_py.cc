#include <components/config.h>
#include "protocols/protocols_py.h"
// http://stackoverflow.com/questions/3761391/boostpython-python-list-to-stdvector
// http://stackoverflow.com/questions/6157409/stdvector-to-boostpythonlist

// C++
#include <vector>
#include <string>

// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

// App
#include "protocols/protocols.h"

using std::vector;
using std::string;
using namespace boost::python;
using boost::shared_ptr;

// App
using protocols::IProtocol;
using protocols::ProtocolsLayerImpl;
using protocols::ReadResult;

BOOST_PYTHON_MODULE(protocols_module)
{
    class_<vector<unsigned char>>("StdVector")
        .def(vector_indexing_suite<vector<unsigned char>>() )
    ;

    class_<ProtocolsLayerImpl, boost::shared_ptr<ProtocolsLayerImpl>>("ProtocolsLayer", init<shared_ptr<IProtocol>>())
      .def("send", &ProtocolsLayerImpl::Send)
      .def("receive_pkg", &ProtocolsLayerImpl::ReceivePkg)
      
      .def_readonly("kCommandCode",&ProtocolsLayerImpl::kCommandCode)
      .def_readonly("kNothingByte",&ProtocolsLayerImpl::kNothingByte)
      .def_readonly("kOnCode",&ProtocolsLayerImpl::kOnCode)
      .def_readonly("kOffCode",&ProtocolsLayerImpl::kOffCode)
    ;

    class_<ReadResult>("ReadResult")
      .def_readonly("type_message", &ReadResult::type_message)
      .def_readonly("data", &ReadResult::data)
      .def_readonly("error_code", &ReadResult::error_code)
        ;

    class_<IProtocol, boost::shared_ptr<IProtocol>>("OldProtocol")
      .def("reset_layer", &IProtocol::resetLayerParameters)
    ;
}

void init_protocols_py_module() {
  initprotocols_module();
}

namespace boost
{

#ifdef BOOST_NO_EXCEPTIONS

void throw_exception(std::exception const & e) {
    throw e;
}; // user defined

#else

//[Not user defined --Dynguss]
template<class E> inline void throw_exception(E const & e)
{
    throw e;
}

#endif

} // namespace boost

