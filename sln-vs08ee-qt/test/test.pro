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
    ../../src/myclock_test.cc \
    ../../src/emb/emb_python_test.cc \
    ../../src/design/dependency_injections_test.cc \
    ../../src/std/std_test.cc

INCLUDEPATH = ../../third_party/gmock-1.6.0/fused-src \
    ../../src/ \
    d:/home/third_party/cc/boost_1_55_0 \   # ѕуть к boost
    d:/Python27/include  # ѕуть к питону

HEADERS += \
    ../../src/myclock.h \
    ../../src/preamplifiers_hieracrhy.h \
    ../../src/design/preamplifiers_hieracrhy.h

LIBS += d:/Python27/libs/python27.lib
LIBS += d:/home/third_party/cc/boost_1_55_0/builded_lib/msvc-9.0/lib/boost_python-vc90-mt-gd-1_55.lib
LIBS += d:/home/third_party/cc/boost_1_55_0/builded_lib/msvc-9.0/lib/boost_python-vc90-mt-1_55.lib
