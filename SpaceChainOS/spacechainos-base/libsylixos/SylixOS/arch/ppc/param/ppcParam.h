/*********************************************************************************************************
**
**                                    中国软件开源组织
**
**                                   嵌入式实时操作系统
**
**                                SylixOS(TM)  LW : long wing
**
**                               Copyright All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: ppcParam.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2016 年 04 月 27 日
**
** 描        述: PowerPC 体系构架启动参数.
*********************************************************************************************************/

#ifndef __PPCPARAM_H
#define __PPCPARAM_H

/*********************************************************************************************************
  启动参数
*********************************************************************************************************/

typedef struct {
    BOOL        PP_bGenericPPC32;
} PPC_PARAM;

/*********************************************************************************************************
  获取启动参数
*********************************************************************************************************/

PPC_PARAM  *archKernelParamGet(VOID);

#endif                                                                  /*  __PPCPARAM_H               */
/*********************************************************************************************************
  END
*********************************************************************************************************/
