# $id$
#
#
#
#
#

CONFIG += debug warn_on
CONFIG += ordered

OBJECTS_DIR = $$(LMNGT_BUILD)/obj

LMNGT_SANDBOX     = $$(LMNGT_BUILD)
LMNGT_SANDBOX_BIN = $$LMNGT_SANDBOX/bin
LMNGT_SANDBOX_LIB = $$LMNGT_SANDBOX/lib
LMNGT_SANDBOX_INC = $$LMNGT_SANDBOX/include
LMNGT_SANDBOX_SRC = $$LMNGT_SANDBOX/src
LMNGT_SANDBOX_MOC = ./moc_cpp

QWT_DIR = $$(QWT)
QWT_LIB = $$QWT_DIR/lib
QWT_SRC = $$QWT_DIR/src

QT += sql
QT += xml

QMAKE_CXXFLAGS += -fPIC -fmessage-length=0
QMAKE_CFLAGS   += -fPIC -fmessage-length=0i

# Additional optimizations for release build
QMAAKE_CXXFLAGS += -finline-functions
QMAAKE_CFLAGS   += -finline-functions
