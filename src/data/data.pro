######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = lib

INCLUDEPATH += \
              $$LMNGT_SANDBOX_SRC/util \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
        -lutil \
        #

CONFIG += staticlib

TARGET = data 
DESTDIR = $$LMNGT_SANDBOX_LIB 

# Input
SOURCES += \
           trip.cpp \
           location.cpp \
           #

HEADERS += \
           trip.h \
           location.h \
           #

QMAKE_CXXFLAGS += -fno-strict-aliasing
QMAKE_CFLAGS   += -fno-strict-aliasing
