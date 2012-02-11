######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = lib

INCLUDEPATH += \
              #

CONFIG += staticlib

TARGET = dbcon 
DESTDIR = $$LMNGT_SANDBOX_LIB 

# Input
SOURCES += \
           databaseConnection.cpp \
           #

HEADERS += \
           databaseConnection.h \
           #

QMAKE_CXXFLAGS += -fno-strict-aliasing
QMAKE_CFLAGS   += -fno-strict-aliasing
