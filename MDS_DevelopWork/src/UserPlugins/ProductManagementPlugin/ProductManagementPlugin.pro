#/****************************************************************************
#**
#**
#**
#**
#**
#/****************************************************************************

#include
include(../../BaseTotalPri/BaseTotal.pri) 
TEMPLATE = lib 


#QT Model:core gui widgets xml sql webkit network
QT  += core gui 
greaterThan(QT_MAJOR_VERSION,4):QT += widgets 
CONFIG += c++14 
TARGET = ProductManagementPlugin 
ORIGINAL_TARGET = $$TARGET 

#PROJECT_PATH
INCLUDE_DIR     = $${DEV_HOME}/include 
DEST_DIR_D      = $${DEV_HOME}/dbin$${QT_VERSION} 
DEST_DIR_R      = $${DEV_HOME}/rbin$${QT_VERSION} 
LIB_DIR         = $${DEV_HOME}/libs 

# INCLUDE_PATH 
INCLUDEPATH += $${INCLUDE_DIR}/HMPCoreFrame 
INCLUDEPATH += $${INCLUDE_DIR}/HMPPluginFrame 
INCLUDEPATH += $${INCLUDE_DIR}/ 

win32{ 
CONFIG(debug,debug|release){ 
    DESTDIR = $${DEST_DIR_D}/plugins 
    LIBS += -L$$PWD/../../libs/ 
    LIBS += -L$$DEST_DIR_D/ 
    LIBS += -lHMPCore 
    LIBS += -lHMPPluginFrame 
} 
CONFIG(release,debug|release){ 
    DESTDIR = $${DEST_DIR_R}/plugins
    LIBS += -L$$PWD/../../libs/ 
    LIBS += -L$$DEST_DIR_R/ 
    LIBS += -lHMPCore 
    LIBS += -lHMPPluginFrame 
} 
} 
else:unix{ 
CONFIG(debug,debug|release){ 
    DESTDIR = $${DEST_DIR_D}/plugins 
    LIBS += -L$${DEST_DIR_D} 
    LIBS += -lHMPCore 
    LIBS += -lHMPPluginFrame 
} 
CONFIG(release,debug|release){ 
    DESTDIR = $${DEST_DIR_R}/plugins
    LIBS += -L$${DEST_DIR_R} 
    LIBS += -lHMPCore 
    LIBS += -lHMPPluginFrame 
} 
} 

HEADERS += \
    DetectorPage.h \
    FastImagerPage.h \
    ImagerPage.h \
    ProductManagementDialog.h \
    StellarPredictionPage.h \
    iproductmanagementpluginservice.h  \ 
    productmanagementpluginservice.h  \ 
    productmanagementpluginactivator.h 

SOURCES += \
    DetectorPage.cpp \
    FastImagerPage.cpp \
    ImagerPage.cpp \
    ProductManagementDialog.cpp \
    StellarPredictionPage.cpp \
    productmanagementpluginservice.cpp \ 
    productmanagementpluginactivator.cpp 

RESOURCES += \
    $$PWD/res.qrc 

HeadPath = $$absolute_path($$PWD\\..\\$$TARGET\\iProductManagementPluginservice.h) 
CopyDir = $$absolute_path($${INCLUDE_DIR}\\$$TARGET\\) 

HeadPath = $$replace(HeadPath, /, \\) 
CopyDir = $$replace(CopyDir, /, \\) 

!exists($$CopyDir) 
{ 
    mkpath($$CopyDir) 
} 

QMAKE_POST_LINK += copy  $$HeadPath $$CopyDir 

FORMS += \
    DetectorPage.ui \
    FastImagerPage.ui \
    ImagerPage.ui \
    ProductManagementDialog.ui \
    StellarPredictionPage.ui

