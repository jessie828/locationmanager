######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = lib

INCLUDEPATH += \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
        #

CONFIG += staticlib

TARGET = util
DESTDIR = $$LMNGT_SANDBOX_LIB 

# Input
SOURCES += \
           util.cpp \
           #

HEADERS += \
           util.h \
           #

QMAKE_CXXFLAGS += -fno-strict-aliasing
QMAKE_CFLAGS   += -fno-strict-aliasing
