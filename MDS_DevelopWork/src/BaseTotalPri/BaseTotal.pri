#--------------------------------------------------------------------------#
#说明：所有项目均需要包含该头文件
#日期：2019-11-09
#
#--------------------------------------------------------------------------#

#产品版本
DEV_HOME = $${PWD}/../../01DeskTopRunHome

#产品信息说明
QMAKE_TARGET_COMPANY    = xxxx Coo.,ltp.
QMAKE_TARGET_PRODUCT    = XX
QMAKE_TARGET_DESCRIPTION= XXXXXXXXXXXXXXXXXXXXXX.
QMAKE_TARGET_COPYRIGHT  =copyright (C) 2019 xxxxxx Coo.,ltp.

#ICE位置
ICE_DIR_D       =$${DEV_HOME}/lib/win/zeroc.ice.v140.3.7.5/build/native/lib/x64/Debug
ICE_DIR_R       =$${DEV_HOME}/lib/win/zeroc.ice.v140.3.7.5/build/native/lib/x64/Release

INCLUDE_DIR =$${DEV_HOME}/include
#GDAL位置
GDAL_DIR_D       =$${DEV_HOME}/lib/win/gdal
GDAL_DIR_R       =$${DEV_HOME}/lib/win/gdal
