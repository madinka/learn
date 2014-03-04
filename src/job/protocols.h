/**
  file : #include <protocols/protocols.h>

  для размышления
  void updateInfo()
{
  ...
}

map <string, void (*)()> mFunctions;
mFunctions["updateInfo"] = updateInfo;
//и так далее для всех функций, что нужно использовать
...
string sFunctionName;
... 
//где-то там считали имя функции

mFunctions[sFunctionName]();//выполнили нужную функцию
mFunctions["updateInfo"]();//то же самое

Updated 11.04.2007
[Сразу несколько человек в комментариях заметили, что 
есть способ лучше, предложенный Александреску в "Современном проектировании".]
*/

#ifndef _PROTOCOLS
#define _PROTOCOLS
// C++
#include <memory>
#include <string>

// Third party
#include <boost/shared_ptr.hpp>

// Other
// for debug
#include <uni_convertors/simple_type_processors.h>
#include <tools/for_debug.h>
// Интерфейсы
#include <transports/rs485.h>
#include <transports/udp_exchange_classes.h>

typedef int ErrCode;
typedef std::string Settings;
/// /// ///
///
///
namespace protocols {
/**

  TODO : 
    сделать интерфейсом и наследовать 
    поменять имена функций на общепринятые 
*/
class IProtocol {
  // получение указателя на передающий уровень
public : 
  virtual ~IProtocol(void);
  IProtocol();
  
  // Функции отправки
  // передается массив с данными и методом их вывода на консоль
  BOOL send( _FormatRS485Data* pDataRS485, void (*printTx)(UCHAR*, int));
  BOOL receive( FormatDataToSend* pDataRS485, void (*printRx)(UCHAR*, int) );

  // проверка работоспособности транспортного уровня
  const BOOL testValidTransLayer() const;

  // для настройки транспортного уровня - очень плохая идея!!
  virtual ErrCode resetLayerParameters( Settings set );
  virtual ErrCode freeTransportLayer();

private : 
  // Объект отправитель данных
  mutable Ifaces::RS485 _rs485;

  // внутренние буфферы
  unsigned char ReceiveTempData[1024];
  int BadMess;
  unsigned char OldReceiveByte;

#ifdef CONTENT_UDP_CLIENT
  ::CRITICAL_SECTION csUDPSender_;
  std::auto_ptr<transport_layers::IHardIfaceTop> hift_;
  // отправка сообщения
  void sendMsg_( const FormatMsg& scTx );
  // создание udp-клиента
  
#endif
  void init_();
};

  // функции раскраски 
void printTx(UCHAR*, int);
void printRx(UCHAR*, int);
void p0(UCHAR*, int);

class Package {
public:
  Package() : type_message(0) {}
  unsigned char type_message;
  std::vector<unsigned char> data;
};

class ProtocolsLayer {
 public:
   virtual ~ProtocolsLayer() {}
   virtual int Send(const unsigned char type_message,
                    const std::vector<unsigned char> & package) = 0;
   virtual int Receive(unsigned char& type_message,
                       std::vector<unsigned char> & package) = 0;

  // TODO:
  //virtual int IsConnected() const = 0;
};

class ReadResult {
public:
  unsigned char type_message;
  std::vector<unsigned char> data;
  unsigned char error_code;
};

class ProtocolsLayerImpl : public ProtocolsLayer {
 public:
   explicit ProtocolsLayerImpl(boost::shared_ptr<IProtocol> old_protocol) {
    old_protocol_ = old_protocol;
  }
   virtual int Send(const unsigned char type_message,
                    const std::vector<unsigned char> & package);
   virtual int Receive(unsigned char& type_message,
                       std::vector<unsigned char> & package);

  ReadResult ReceivePkg();

   static const unsigned char kGetPreamplAndDetectorSample = 0x02;
   static const unsigned char kGetTA12Sample = 0x01;
   static const unsigned char kGetTA34Sample = 0x04;
   static const unsigned char kCommandCode = 0x03;
   //static const unsigned char kGetChannelData = 0x06;
   static const unsigned char kGetChannelData = 0x07;

   static const unsigned char kNothingByte = 0x00;


   // Commands
   static const unsigned char kOnCode = 0xA0;
   static const unsigned char kOffCode = 0xA1;
   static const unsigned char kLockCode = 0x1F;
   static const unsigned char kUnlockCode = 0x1E;

   // detector
   //void CMonoblockView::OnChangeBuddy13() - out power
   //void CMonoblockView::OnChangeBuddy14() - ref. power
   //void CMonoblockView::OnChangeBuddy15() - twr threshold

   // preampl.
   //void CMonoblockView::OnChangeBuddy8() - V feedback
   static const unsigned char kPASaveFeedBackCode = 0x1B;

 private:
   boost::shared_ptr<IProtocol> old_protocol_;
};

}  // end namespace
#endif
