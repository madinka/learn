#pragma once
#define BOOST_NO_EXCEPTIONS
// C++
#include <iostream>

// Third party
#include <boost/python.hpp>
using namespace boost::python;
using boost::shared_ptr;


// App
#include "logger.h"

void init_hello_ext_module();  // иначе модуль не инициализируест и прогр. сломается

