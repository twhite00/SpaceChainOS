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
** 文   件   名: libgen.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2012 年 09 月 17 日
**
** 描        述: 模式匹配函数定义, 需要外部库支持.
*********************************************************************************************************/

#ifndef __LIBGEN_H
#define __LIBGEN_H

#include "sys/cdefs.h"

__BEGIN_DECLS
char	*basename(char *);
char	*dirname(char *);
__END_DECLS

#endif                                                                  /*  __LIBGEN_H                  */
/*********************************************************************************************************
  END
*********************************************************************************************************/
