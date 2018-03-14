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
** 文   件   名: mipsUnaligned.h
**
** 创   建   人: Jiao.JinXing (焦进星)
**
** 文件创建日期: 2015 年 12 月 25 日
**
** 描        述: MIPS 非对齐处理.
*********************************************************************************************************/

#ifndef __ARCH_MIPSUNALIGNED_H
#define __ARCH_MIPSUNALIGNED_H

/*********************************************************************************************************
  MIPS 非对齐处理
*********************************************************************************************************/

ULONG  mipsUnalignedHandle(ARCH_REG_CTX  *pregctx, addr_t  ulAbortAddr);

#endif                                                                  /*  __ARCH_MIPSUNALIGNED_H      */
/*********************************************************************************************************
  END
*********************************************************************************************************/
