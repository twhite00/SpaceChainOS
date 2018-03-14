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
** 文   件   名: monetary.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2012 年 09 月 17 日
**
** 描        述: 货币类型, 需要外部库支持 (locale).
*********************************************************************************************************/

#ifndef __MONETARY_H
#define __MONETARY_H

#include "sys/cdefs.h"
#include <stddef.h>

__BEGIN_DECLS
ssize_t	strfmon(char * __restrict, size_t, const char * __restrict, ...)
                __attribute__((__format__(__strfmon__, 3, 4)));
__END_DECLS

#endif                                                                  /*  __MONETARY_H                */
/*********************************************************************************************************
  END
*********************************************************************************************************/
