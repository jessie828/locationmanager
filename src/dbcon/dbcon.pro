######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = lib

INCLUDEPATH += \
              $$LMNGT_SANDBOX_SRC/util \
              $$LMNGT_SANDBOX_SRC/data/ \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
         -lutil \
         -ldata \
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
