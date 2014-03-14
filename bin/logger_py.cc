#include "logger_py.h"

// ������� ������� ��������� � ������
// ������������� ������ �� �++ - inithello_ext
BOOST_PYTHON_MODULE(hello_ext)  
{
  def("greet", greet)
    ;

  // ���� ���, �� �� �������� ��� ��� �������� ������ ������
  //class_<World>("World", init<std::string>())
  //  .def("greet", &World::greet)
  //  .def("set", &World::set)
  //  ;

  class_<World, boost::shared_ptr<World>>("World", init<std::string>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    ;
    

  // WorldPtr
  class_<Hello, boost::shared_ptr<Hello> >("Hello", /*�������� �����������*/init< std::string >()) 
    .def("say", &Hello::say)
  ;
    
  class_<Talker, boost::shared_ptr<Talker> >("Talker", init<shared_ptr<Hello>>())
      .def("say", &Talker::say)
    ;
}

// ��� �������������
void init_hello_ext_module() {
  inithello_ext();  // ����� ��� ��� �������
}