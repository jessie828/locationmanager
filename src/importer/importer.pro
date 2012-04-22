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
              $$LMNGT_SANDBOX_SRC/dbcon/ \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
         -lutil \
         -ldata \
         -ldbcon \
        #

CONFIG += staticlib

TARGET = importer 
DESTDIR = $$LMNGT_SANDBOX_LIB 

# Input
SOURCES += \
           saxHandler.cpp \
           csvHandler.cpp \
           #

HEADERS += \
           saxHandler.h \
           cxvHandler.h \
           #

QMAKE_CXXFLAGS += -fno-strict-aliasing
QMAKE_CFLAGS   += -fno-strict-aliasing
