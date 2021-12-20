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
TARGET = ReportTablePlugin 
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
    FaultMsgPage.h \
    HeaderView.h \
    LoadFilePage.h \
    LogMsgPage.h \
    NotEditableDelegate.h \
    ReportTablePage.h \
    TableAnalyse.h \
    ireporttablepluginservice.h  \ 
    reporttablepluginservice.h  \ 
    reporttablepluginactivator.h 

SOURCES += \
    FaultMsgPage.cpp \
    HeaderView.cpp \
    LoadFilePage.cpp \
    LogMsgPage.cpp \
    NotEditableDelegate.cpp \
    ReportTablePage.cpp \
    TableAnalyse.cpp \
    reporttablepluginservice.cpp \ 
    reporttablepluginactivator.cpp 

RESOURCES += \
    $$PWD/res.qrc \
    Resource/MyResource.qrc

HeadPath = $$absolute_path($$PWD\\..\\$$TARGET\\iReportTablePluginservice.h) 
CopyDir = $$absolute_path($${INCLUDE_DIR}\\$$TARGET\\) 

HeadPath = $$replace(HeadPath, /, \\) 
CopyDir = $$replace(CopyDir, /, \\) 

!exists($$CopyDir) 
{ 
    mkpath($$CopyDir) 
} 

QMAKE_POST_LINK += copy  $$HeadPath $$CopyDir 

FORMS += \
    FaultMsgPage.ui \
    LoadFilePage.ui \
    LogMsgPage.ui \
    ReportTablePage.ui

