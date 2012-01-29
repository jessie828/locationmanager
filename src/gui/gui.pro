######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = app

INCLUDEPATH += \
              ./uic_headers/ \
              #
LIBS += \
        #

TARGET = locationManager.exe

DESTDIR = $$LMNGT_SANDBOX_BIN 
MOC_DIR = ./moc_cpp
UI_SOURCES_DIR = ./uic_cpp
UI_HEADERS_DIR = ./uic_headers

# Input
SOURCES += \
           mainWindow.cpp \
           main.cpp \
           #

HEADERS += \
           mainWindow.h \
           #

FORMS += \
         mainWindow.ui \
         #
