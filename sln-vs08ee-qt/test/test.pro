#-------------------------------------------------
#
# Project created by QtCreator 2014-02-11T14:05:10
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ../../src/small-tests-launcher.cc \
    ../../third_party/gmock-1.6.0/fused-src/gmock-gtest-all.cc \
    ../../src/myclock.cc \
    ../../src/myclock_test.cc

INCLUDEPATH = C:\home\sinetova-madina\learn\third_party\gmock-1.6.0\fused-src

HEADERS += \
    ../../src/myclock.h
