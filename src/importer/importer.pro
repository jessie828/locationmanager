######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = lib

INCLUDEPATH += \
              $$LMNGT_SANDBOX_SRC/data/ \
              $$LMNGT_SANDBOX_SRC/dbcon/ \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
         -ldata \
         -ldbcon \
        #

CONFIG += staticlib

TARGET = importer 
DESTDIR = $$LMNGT_SANDBOX_LIB 

# Input
SOURCES += \
           saxHandler.cpp \
           #

HEADERS += \
           saxHandler.h \
           #

QMAKE_CXXFLAGS += -fno-strict-aliasing
QMAKE_CFLAGS   += -fno-strict-aliasing
