#*********************************************************************************************************
#
#                                    中国软件开源组织
#
#                                   嵌入式实时操作系统
#
#                                SylixOS(TM)  LW : long wing
#
#                               Copyright All Rights Reserved
#
#--------------文件信息--------------------------------------------------------------------------------
#
# 文   件   名: mime.mk
#
# 创   建   人: RealEvo-IDE
#
# 文件创建日期: 2016 年 10 月 08 日
#
# 描        述: 本文件由 RealEvo-IDE 生成，用于配置 Makefile 功能，请勿手动修改
#*********************************************************************************************************

#*********************************************************************************************************
# Clear setting
#*********************************************************************************************************
include $(CLEAR_VARS_MK)

#*********************************************************************************************************
# Target
#*********************************************************************************************************
LOCAL_TARGET_NAME := mime.so

#*********************************************************************************************************
# Source list
#*********************************************************************************************************
LOCAL_SRCS := \
luasocket/src/mime.c \
luasocket/src/compat.c

#*********************************************************************************************************
# Header file search path (eg. LOCAL_INC_PATH := -I"Your hearder files search path")
#*********************************************************************************************************
LOCAL_INC_PATH := 
LOCAL_INC_PATH += $(LUA_INC_PATH)

#*********************************************************************************************************
# Pre-defined macro (eg. -DYOUR_MARCO=1)
#*********************************************************************************************************
LOCAL_DSYMBOL := -DLUA_COMPAT_ALL
LOCAL_DSYMBOL += -DLUA_COMPAT_5_1
LOCAL_DSYMBOL += -DLUA_COMPAT_5_2

LOCAL_DSYMBOL += -DLUASOCKET_DEBUG
LOCAL_DSYMBOL += -DUNIX_HAS_SUN_LEN

LOCAL_DSYMBOL += -DLUASOCKET_API='__attribute__((visibility("default")))'
LOCAL_DSYMBOL += -DUNIX_API='__attribute__((visibility("default")))'
LOCAL_DSYMBOL += -DMIME_API='__attribute__((visibility("default")))'

#*********************************************************************************************************
# Depend library (eg. LOCAL_DEPEND_LIB := -la LOCAL_DEPEND_LIB_PATH := -L"Your library search path")
#*********************************************************************************************************
LOCAL_DEPEND_LIB      := 
LOCAL_DEPEND_LIB_PATH := 

#*********************************************************************************************************
# C++ config
#*********************************************************************************************************
LOCAL_USE_CXX        := no
LOCAL_USE_CXX_EXCEPT := no

#*********************************************************************************************************
# Code coverage config
#*********************************************************************************************************
LOCAL_USE_GCOV := no

include $(LIBRARY_MK)

#*********************************************************************************************************
# End
#*********************************************************************************************************
