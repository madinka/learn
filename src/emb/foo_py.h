#ifndef FOO_PY_H
#define FOO_PY_H

// Third party
#include <boost/python.hpp>

// App
#include "foo.h"

void init_hello_module();  // иначе модуль не инициализируест и прогр. сломается


#endif // FOO_PY_H
