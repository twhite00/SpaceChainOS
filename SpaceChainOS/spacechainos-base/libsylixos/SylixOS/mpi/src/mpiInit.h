/*********************************************************************************************************
**
**                                    中国软件开源组织
**
**                                   嵌入式实时操作系统
**
**                                       SylixOS(TM)
**
**                               Copyright  All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: mpInit.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2007 年 04 月 10 日
**
** 描        述: 这是系统多处理器初始化部分函数声明
*********************************************************************************************************/

#ifndef  __MPINIT_H
#define  __MPINIT_H

#if LW_CFG_MPI_EN > 0

VOID  _mpiInit(VOID);

#endif                                                                  /*  LW_CFG_MPI_EN > 0           */

#endif                                                                  /*  __MPINIT_H                  */
/*********************************************************************************************************
  END
*********************************************************************************************************/
