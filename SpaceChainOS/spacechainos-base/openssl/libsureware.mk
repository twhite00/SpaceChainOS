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
# 文   件   名: libsureware.mk
#
# 创   建   人: RealEvo-IDE
#
# 文件创建日期: 2018 年 02 月 06 日
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
LOCAL_TARGET_NAME := libsureware.so

#*********************************************************************************************************
# Source list
#*********************************************************************************************************
LOCAL_SRCS := openssl/engines/e_sureware.c

#*********************************************************************************************************
# Header file search path (eg. LOCAL_INC_PATH := -I"Your header files search path")
#*********************************************************************************************************
LOCAL_INC_PATH := -I"./openssl" -I"./openssl/crypto" -I"./openssl/crypto/modes" \
-I"./openssl/crypto/asn1" -I"./openssl/crypto/evp" -I"./openssl/include"

#*********************************************************************************************************
# Pre-defined macro (eg. -DYOUR_MARCO=1)
#*********************************************************************************************************
LOCAL_DSYMBOL := -DOPENSSL_PIC -DOPENSSL_THREADS -D_REENTRANT -DDSO_DLFCN -DHAVE_DLFCN_H -DOPENSSL_USE_BUILD_DATE

ifeq ($(ARCH), sparc)
LOCAL_DSYMBOL += -DB_ENDIAN 
else ifeq ($(ARCH), ppc)
LOCAL_DSYMBOL += -DB_ENDIAN 
else
LOCAL_DSYMBOL += -DL_ENDIAN 
endif

#*********************************************************************************************************
# Compiler flags
#*********************************************************************************************************
LOCAL_CFLAGS   := 
LOCAL_CXXFLAGS := 

#*********************************************************************************************************
# Depend library (eg. LOCAL_DEPEND_LIB := -la LOCAL_DEPEND_LIB_PATH := -L"Your library search path")
#*********************************************************************************************************
LOCAL_DEPEND_LIB      := -lcrypto
LOCAL_DEPEND_LIB_PATH := -L"$(OUTDIR)"

#*********************************************************************************************************
# C++ config
#*********************************************************************************************************
LOCAL_USE_CXX        := no
LOCAL_USE_CXX_EXCEPT := no

#*********************************************************************************************************
# Code coverage config
#*********************************************************************************************************
LOCAL_USE_GCOV := no

#*********************************************************************************************************
# OpenMP config
#*********************************************************************************************************
LOCAL_USE_OMP := no

#*********************************************************************************************************
# User link command
#*********************************************************************************************************
LOCAL_PRE_LINK_CMD   := 
LOCAL_POST_LINK_CMD  := 
LOCAL_PRE_STRIP_CMD  := 
LOCAL_POST_STRIP_CMD := 

#*********************************************************************************************************
# Depend target
#*********************************************************************************************************
LOCAL_DEPEND_TARGET := ./$(OUTDIR)/libcrypto.so

include $(LIBRARY_MK)

#*********************************************************************************************************
# End
#*********************************************************************************************************
