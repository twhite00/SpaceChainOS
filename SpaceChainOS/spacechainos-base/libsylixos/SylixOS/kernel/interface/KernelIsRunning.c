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
** 文   件   名: KernelIsRunning.c
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2007 年 06 月 24 日
**
** 描        述: 检测实时内核是否已经运行。
*********************************************************************************************************/
#define  __SYLIXOS_KERNEL
#include "../SylixOS/kernel/include/k_kernel.h"
/*********************************************************************************************************
** 函数名称: API_KernelIsRunning
** 功能描述: 检测实时内核是否已经运行。
** 输　入  : NONE
** 输　出  : LW_TRUE 系统已经运行，LW_FASLE 系统没有启动
** 全局变量: 
** 调用模块: 
                                           API 函数
*********************************************************************************************************/
LW_API  
BOOL  API_KernelIsRunning (VOID)
{    
    if (LW_SYS_STATUS_IS_RUNNING()) {
        return  (LW_TRUE);
    
    } else {
        return  (LW_FALSE);
    }
}
/*********************************************************************************************************
  END
*********************************************************************************************************/
