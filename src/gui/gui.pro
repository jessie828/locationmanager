######################################################################
#
# Copyright 2012.
#
######################################################################

include(../LocationManagement.pri)

TEMPLATE = app

DYNAMIC_FLAG = -W1,-Bdynamic
STATIC_FLAG = -W1,-Bstatic

CONFIG += no_lflags_merge

INCLUDEPATH += \
              ./uic_headers/ \
              $$LMNGT_SANDBOX_SRC/dbcon/ \
              $$LMNGT_SANDBOX_SRC/data/ \
              $$LMNGT_SANDBOX_SRC/importer/ \
              #

LIBS += \
        -L$$LMNGT_SANDBOX_LIB \
        -limporter \
        -ldata \
        -ldbcon \
        #

TARGET = locationManager.exe

DESTDIR = $$LMNGT_SANDBOX_BIN 
MOC_DIR = ./moc_cpp
UI_SOURCES_DIR = ./uic_cpp
UI_HEADERS_DIR = ./uic_headers

# Input
SOURCES += \
           mainWindow.cpp \
           importDialog.cpp \
           main.cpp \
           #

HEADERS += \
           mainWindow.h \
           importDialog.h \
           #

FORMS += \
         mainWindow.ui \
         importDialog.ui \
         #
