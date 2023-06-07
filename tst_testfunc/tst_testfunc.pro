QT += testlib
QT += core network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_func.cpp \
    ../hallServer/func_for_server.cpp \
    ../hallServer/mytcpserver.cpp


SUBDIRS += \


HEADERS += \
    ../hallServer/func_for_server.h \
    ../hallServer/mytcpserver.h

