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
** 文   件   名: s_utime.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2008 年 09 月 19 日
**
** 描        述: POSIX utime.h 头文件. (修改文件时间)
*********************************************************************************************************/

#ifndef __S_UTIME_H
#define __S_UTIME_H

/*********************************************************************************************************
  相关结构定义 (actime, modtime 为 UTC 时间)
*********************************************************************************************************/

struct utimbuf {
    time_t      actime;                                                 /*  设置访问时间                */
    time_t      modtime;                                                /*  设置修改时间                */
};

/*********************************************************************************************************
  POSIX API
*********************************************************************************************************/

LW_API  INT  utime(CPCHAR  pcFile, const struct utimbuf *utimbNew);
LW_API  INT  utimes(CPCHAR  pcFile, struct timeval tvp[2]);
LW_API  INT  futimes(INT iFd, struct timeval tvp[2]);

#endif                                                                  /*  __S_UTIME_H                 */
/*********************************************************************************************************
  END
*********************************************************************************************************/
