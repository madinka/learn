#ifndef PREAMPLIFIERS_HIERACRHY_H
#define PREAMPLIFIERS_HIERACRHY_H

// Third party
#include <boost/shared_ptr.hpp>


// Абстрактный класс
class Preamplifier {
public:
    virtual ~Preamplifier () {}
    virtual int SetChannel(const int value) = 0;
};

class PreamplifierImplFake : public Preamplifier {
public:
    PreamplifierImplFake() {}
    virtual int SetChannel(const int value) {
        channel_ = value;
        return 0;
    }
private:
    int channel_;
};

class PreamplifierImplReal : public Preamplifier {
public:
    PreamplifierImplReal() {}
    virtual int SetChannel(const int value) {
        channel_ = value;
        printf("channel = %d\n", value);
        return 0;
    }
private:
    int channel_;
    int eeprom_[20];
};

// BAD, but now bee so
class PreamplifierWrapper : public Preamplifier {
 public:
   PreamplifierWrapper(boost::shared_ptr<Preamplifier> real_ptr) : real_ptr_(real_ptr) {
  }
   virtual int SetChannel(const int value) {
     printf("channel = %d\n", value);
    return real_ptr_->SetChannel(value);
   }
private:
  boost::shared_ptr<Preamplifier> real_ptr_;
};

#endif // PREAMPLIFIERS_HIERACRHY_H
