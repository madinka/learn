// C++
#include <iostream>
#include "logger.h"
//
#include <boost/python.hpp>
using namespace boost::python;
using boost::shared_ptr;
//using std::shared_ptr;

char const* greet()
{
return "hello, world!";
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