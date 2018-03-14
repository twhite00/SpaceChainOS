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
** 文   件   名: inlWordAlign.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2006 年 12 月 17 日
**
** 描        述: 这是系统将字节数量转为字对齐的数量。
*********************************************************************************************************/

#ifndef  __INLWORDALIGN_H
#define  __INLWORDALIGN_H

/*********************************************************************************************************
  将字节数量转为字对齐的数量
*********************************************************************************************************/

static LW_INLINE size_t  _CalWordAlign (size_t  stByteSize)
{
    return  ((size_t)(stByteSize / sizeof(LW_STACK)));
}

#endif                                                                  /*  __INLWORDALIGN_H            */
/*********************************************************************************************************
  END
*********************************************************************************************************/
