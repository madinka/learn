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
#include "applications-server-cross/crosscuttings/logger.h"


class Foo {
  public:
    Foo(int j) { i=new int[j]; }
    ~Foo() { delete i; }
  private:
    int* i;
};

/*
class Bar: Foo {
  public:
    Bar(int j) { i = new char[j]; }
    ~Bar() { delete i; }
  private:
    char* i;
};
*/


int main(int argc, char* argv[])
{

  /*Foo* f=new Foo(100);
  Foo* b=new Bar(200);
  *f=*b;
  delete f;
  delete b;*/

  // Получаем текущую локаль CRT (если нужно потом восстановить)
  char* crtLocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, ".1251");

  // инициализация вывода в лог - нужно для тест. приложения
  // если закомменчено выводит ошибки на консоль, а не в лог
  //::crosscuttings::loggers::InitLogger();  

  // Run
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(print_time) = true;
  RUN_ALL_TESTS();
  setlocale(LC_ALL, crtLocale);
  return 0;
}

