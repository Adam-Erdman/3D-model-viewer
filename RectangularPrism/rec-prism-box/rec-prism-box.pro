TEMPLATE = app
TARGET   = RectangularPrismBox

CONFIG += warn_off
QT += widgets axserver

HEADERS  = \
           PrismObjWindow.h \
           RecPrismBox.h
SOURCES  = \
           PrismObjWindow.cpp \
           RecPrismBox.cpp \
           main.cpp

RC_FILE = recprism.rc
DEF_FILE = recprism.def

target.path = /tmp/$${TARGET}/
INSTALLS += target
