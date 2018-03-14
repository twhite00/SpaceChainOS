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
** 文   件   名: nl_reent.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2011 年 08 月 15 日
**
** 描        述: newlib fio 兼容层. (SylixOS 和 VxWorks 类似, 必须使用自己的 libc 库)
                 很多 gcc 使用 newlib 作为 libc, 其他的库也都依赖于 newlib, 例如 libstdc++ 库, 
                 SylixOS 要想使用这些库, 则必须提供一个 newlib reent 兼容的接口.
*********************************************************************************************************/

#ifndef __NL_REENT_H
#define __NL_REENT_H

/*********************************************************************************************************
  裁剪宏
*********************************************************************************************************/
#if (LW_CFG_DEVICE_EN > 0) && (LW_CFG_FIO_LIB_EN > 0)

VOID   lib_nlreent_init(LW_OBJECT_HANDLE  ulThread);
FILE **lib_nlreent_stdfile(INT  FileNo);

#endif                                                                  /*  LW_CFG_DEVICE_EN > 0        */
                                                                        /*  LW_CFG_FIO_LIB_EN > 0       */
                                                                        
#endif                                                                  /*  __NL_REENT_H                */
/*********************************************************************************************************
  END
*********************************************************************************************************/
