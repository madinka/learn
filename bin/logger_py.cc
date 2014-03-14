#include "logger_py.h"

// Обертки классов собранные в модуль
// Инициализация модуля из С++ - inithello_ext
BOOST_PYTHON_MODULE(hello_ext)  
{
  def("greet", greet)
    ;

  // Если так, то по значения или для создание внутри питона
  //class_<World>("World", init<std::string>())
  //  .def("greet", &World::greet)
  //  .def("set", &World::set)
  //  ;

  class_<World, boost::shared_ptr<World>>("World", init<std::string>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    ;
    

  // WorldPtr
  class_<Hello, boost::shared_ptr<Hello> >("Hello", /*Основной конструктор*/init< std::string >()) 
    .def("say", &Hello::say)
  ;
    
  class_<Talker, boost::shared_ptr<Talker> >("Talker", init<shared_ptr<Hello>>())
      .def("say", &Talker::say)
    ;
}

// Для инициализации
void init_hello_ext_module() {
  inithello_ext();  // лежит там где обертка
}