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
** 文   件   名: armMpCore.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2013 年 12 月 09 日
**
** 描        述: ARM 体系构架多核内部底层接口.
*********************************************************************************************************/

#ifndef __ARMMPCORE_H
#define __ARMMPCORE_H

/*********************************************************************************************************
  ARM 自旋锁
*********************************************************************************************************/

VOID                     armSpinLock(volatile SPINLOCKTYPE  *psl);
volatile SPINLOCKTYPE    armSpinTryLock(volatile SPINLOCKTYPE  *psl);
VOID                     armSpinUnlock(volatile SPINLOCKTYPE  *psl);

#endif                                                                  /*  __ARMMPCORE_H               */
/*********************************************************************************************************
  END
*********************************************************************************************************/
