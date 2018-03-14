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
** 文   件   名: cpp_cpp.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2009 年 10 月 14 日
**
** 描        述: 操作系统平台 C++ 内存支持库. 
                (为内核模块提供简单的 C++ 支持, 应用程序则使用 libstdc++ or libsupc++)
*********************************************************************************************************/

#ifndef __CPP_CPP_H
#define __CPP_CPP_H

#ifdef  __cplusplus

/*********************************************************************************************************
  new delete 重载
*********************************************************************************************************/
#include  <stddef.h>                                                    /*  need size_t type            */

#ifdef __SYLIXOS_KERNEL

void  *operator  new(size_t   stSize);
void  *operator  new[](size_t   stSize);
void   operator  delete(void  *pvMem);
void   operator  delete[](void  *pvMem);

#endif                                                                  /*  __SYLIXOS_KERNEL            */

#endif                                                                  /*  __cplusplus                 */
#endif                                                                  /*  __CPP_CPP_H                 */
/*********************************************************************************************************
  END
*********************************************************************************************************/
