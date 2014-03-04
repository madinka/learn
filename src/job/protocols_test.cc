#include "components/config.h"
#include "protocols/protocols.h"

// C++
#include <string>


// Third party
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>

using std::string;
using boost::shared_ptr;

using protocols::IProtocol;
using protocols::ProtocolsLayer;
using protocols::Package;
using protocols::ProtocolsLayerImpl;

static string portName = "COM7";

TEST(Dal, ReadRequest) {
  IProtocol protocol;
  protocol.resetLayerParameters(portName);

  Package requestPkg;
  requestPkg.type_message = ProtocolsLayerImpl::kGetPreamplAndDetectorSample;
  requestPkg.data.push_back(0);
  
  // посылаем мониторящие сообщения
  FormatRS485Data request = {0x1F,
      requestPkg.type_message,
      requestPkg.data.size(),
      &requestPkg.data[0]};

  void (*printRx)(UCHAR*, int); 
  printRx = &protocols::p0; // для индикации при отладке
  EXPECT_EQ(true, protocol.send(&request, printRx));

  Package responsePkg;
  responsePkg.data.resize(512, 0);

  FormatDataToSend response = {0x00, 0x00, 0x00, &responsePkg.data[0]};

  // Проверка 
  EXPECT_EQ(true, protocol.testValidTransLayer());
  BOOL receiveRequest = protocol.receive(&response, &protocols::printRx);
  EXPECT_EQ(true, receiveRequest);
  EXPECT_EQ(32, response.LengthDataMessage);
}

TEST(Dal, UpdatedProtocol) {
  shared_ptr<IProtocol> old_protocol(new IProtocol());
  old_protocol->resetLayerParameters(portName);

  shared_ptr<ProtocolsLayer> protocol(new ProtocolsLayerImpl(old_protocol));

  // Отпревляем запрос
  Package request;
  request.type_message = ProtocolsLayerImpl::kGetPreamplAndDetectorSample;
  request.data.push_back(0);
  EXPECT_EQ(true, protocol->Send(request.type_message, request.data));

  Package response;
  response.data.resize(512, 0);
  EXPECT_EQ(true, protocol->Receive(response.type_message, response.data));
  EXPECT_EQ(32, response.data.size());
}

TEST(Dal, FeedBackUp) {
  shared_ptr<IProtocol> old_protocol(new IProtocol());
  old_protocol->resetLayerParameters(portName);

  shared_ptr<ProtocolsLayer> protocol(new ProtocolsLayerImpl(old_protocol));

  // Отпревляем запрос
  Package request;
  request.type_message = ProtocolsLayerImpl::kGetPreamplAndDetectorSample;
  request.data.push_back(0);
  EXPECT_EQ(true, protocol->Send(request.type_message, request.data));

  Package response;
  response.data.resize(512, 0);
  EXPECT_EQ(true, protocol->Receive(response.type_message, response.data));
  EXPECT_EQ(32, response.data.size());
}

TEST(Dal, SetChannel) {
  string string_representation = "100";
  double frequency = simple_type_processors::string2double(string_representation);
  unsigned char code = static_cast<unsigned char>(frequency);
  code += 0x6B; // добавка

  shared_ptr<IProtocol> old_protocol(new IProtocol());
  old_protocol->resetLayerParameters(portName);

  shared_ptr<ProtocolsLayer> protocols_layer(new ProtocolsLayerImpl(old_protocol));

  // Отпревляем запрос
  Package request;
  request.type_message = ProtocolsLayerImpl::kCommandCode;
  request.data.push_back(code);
  EXPECT_EQ(true, protocols_layer->Send(request.type_message, request.data));
}

TEST(Dal, On) {
  shared_ptr<IProtocol> old_protocol(new IProtocol());
  old_protocol->resetLayerParameters(portName);

  shared_ptr<ProtocolsLayer> protocols_layer(new ProtocolsLayerImpl(old_protocol));

  // Отпревляем запрос
  Package request;
  request.type_message = ProtocolsLayerImpl::kCommandCode;
  request.data.push_back(ProtocolsLayerImpl::kOffCode);
  EXPECT_EQ(true, protocols_layer->Send(request.type_message, request.data));
}

TEST(Dal, ReadChannelData) {
  shared_ptr<IProtocol> old_protocol(new IProtocol());
  old_protocol->resetLayerParameters(portName);

  shared_ptr<ProtocolsLayer> protocols_layer(new ProtocolsLayerImpl(old_protocol));

  // Отпревляем запрос
  Package request;
  request.type_message = ProtocolsLayerImpl::kGetChannelData;
  request.data.push_back(ProtocolsLayerImpl::kNothingByte);
  EXPECT_EQ(true, protocols_layer->Send(request.type_message, request.data));

  Package response;
  response.data.resize(512, 0);
  EXPECT_EQ(true, protocols_layer->Receive(response.type_message, response.data));
  EXPECT_EQ(7, response.data.size());
}






