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
** 文   件   名: cdump.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2017 年 12 月 01 日
**
** 描        述: 系统/应用崩溃信息记录.
*********************************************************************************************************/

#ifndef __CDUMP_H
#define __CDUMP_H

/*********************************************************************************************************
  裁剪支持
*********************************************************************************************************/
#if (LW_CFG_CDUMP_EN > 0) && (LW_CFG_DEVICE_EN > 0)

LW_API INT   API_CrashDumpBuffer(PVOID  pvCdump, size_t  stSize);
LW_API INT   API_CrashDumpSave(CPCHAR  pcLogFile, INT  iFlag, INT  iMode, BOOL  bClear);
LW_API INT   API_CrashDumpShow(INT  iFd, BOOL  bClear);

#endif                                                                  /*  LW_CFG_CDUMP_EN > 0         */
                                                                        /*  LW_CFG_DEVICE_EN > 0        */
#endif                                                                  /*  __CDUMP_H                   */
/*********************************************************************************************************
  END
*********************************************************************************************************/
