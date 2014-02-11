// snmp-agent.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>

/*
msvcprtd.lib(MSVCP90D.dll):-1:
ошибка: LNK2005:
"public: __thiscall std::allocator<char>::allocator<char>(void)"
(??0?$allocator@D@std@@QAE@XZ) already defined in v8_base.ia32.lib(runtime.obj)
*/

// Other
#include <gtest/gtest.h>

// App
using std::cin;

int main(int argc, char* argv[])
{

  // Получаем текущую локаль CRT (если нужно потом восстановить)
  char* crtLocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, ".1251");
  // Run
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(print_time) = true;
  RUN_ALL_TESTS();
  setlocale(LC_ALL, crtLocale);
  //int i = 0;
  system("pause");
  return 0;
}

