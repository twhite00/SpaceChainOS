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
** 文   件   名: KernelMisc.c
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2013 年 03 月 30 日
**
** 描        述: 系统内核杂项功能
*********************************************************************************************************/
#define  __SYLIXOS_KERNEL
#include "../SylixOS/kernel/include/k_kernel.h"
/*********************************************************************************************************
** 函数名称: API_KernelNop
** 功能描述: 内核空函数, 当前未使用
** 输　入  : pcArg                         字串参数
**           lArg                          长整形参数
** 输　出  : NONE
** 全局变量: 
** 调用模块: 
                                           API 函数
*********************************************************************************************************/
LW_API  
VOID  API_KernelNop (CPCHAR  pcArg, LONG  lArg)
{
    (VOID)pcArg;
    (VOID)lArg;
}
/*********************************************************************************************************
  END
*********************************************************************************************************/
