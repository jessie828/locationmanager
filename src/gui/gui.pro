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
              $$QWT_SRC/ \
              $$LMNGT_SANDBOX_SRC/dbcon/ \
              $$LMNGT_SANDBOX_SRC/data/ \
              $$LMNGT_SANDBOX_SRC/importer/ \
              $$LMNGT_SANDBOX_SRC/util/ \
              #

LIBS += \
        -L$$QWT_LIB \
        -L$$LMNGT_SANDBOX_LIB \
        -limporter \
        -ldata \
        -ldbcon \
        -lutil \
        -lqwt \
        #

TARGET = locationManager.exe

DESTDIR = $$LMNGT_SANDBOX_BIN 
MOC_DIR = ./moc_cpp
UI_SOURCES_DIR = ./uic_cpp
UI_HEADERS_DIR = ./uic_headers

# Input
SOURCES += \
           mainWindow.cpp \
           tripImportDialog.cpp \
           multiTripImportDialog.cpp \
           tankImportDialog.cpp \
           histogram.cpp \
           main.cpp \
           #

HEADERS += \
           mainWindow.h \
           tripImportDialog.h \
           multiTripImportDialog.h \
           tankImportDialog.h \
           histogram.h \
           #

FORMS += \
         mainWindow.ui \
         tripImportDialog.ui \
         multiTripImportDialog.ui \
         tankImportDialog.ui \
         #
