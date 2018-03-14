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
** 文   件   名: posixLib.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2009 年 12 月 30 日
**
** 描        述: posix 内部库.
*********************************************************************************************************/

#ifndef __POSIXLIB_H
#define __POSIXLIB_H

#include "SylixOS.h"                                                    /*  操作系统                    */

/*********************************************************************************************************
  裁剪支持
*********************************************************************************************************/
#if LW_CFG_POSIX_EN > 0

#include "px_sched_param.h"

/*********************************************************************************************************
  配置信息 
  if LW_CFG_LOWEST_PRIO = 255 (min = 1 max = 254)
*********************************************************************************************************/

#define __PX_PRIORITY_MAX               PX_PRIORITY_CONVERT(1)          /*  建议不能设为最高            */
#define __PX_PRIORITY_MIN               PX_PRIORITY_CONVERT((LW_PRIO_LOWEST - 1))
                                                                        /*  比 idle 稍高                */
/*********************************************************************************************************
  POSIX 线程数据结构 (当前未使用)
*********************************************************************************************************/

typedef struct {
    PVOID                   PCTX_pvReserve;                             /*  暂时未使用                  */
} __PX_CONTEXT;                                                         /*  pthread 上下文              */

/*********************************************************************************************************
  POSIX 进程数据结构
*********************************************************************************************************/

typedef struct {
#if LW_CFG_GJB7714_EN > 0
    INT                     PVPCTX_iPSemOpenMethod;
    INT                     PVPCTX_iPMqOpenMethod;
#endif                                                                  /*  LW_CFG_GJB7714_EN > 0       */
    INT                     PVPCTX_iThreadDefMethod;
    PVOID                   PVPCTX_pvReserve;
} __PX_VPROC_CONTEXT;

/*********************************************************************************************************
  线程私有数据类型
*********************************************************************************************************/

typedef struct {
    LW_LIST_LINE            PKEYD_lineManage;                           /*  双向链表                    */
    LW_OBJECT_HANDLE        PKEYD_ulOwner;                              /*  所有者                      */
    long                    PKEYD_lId;                                  /*  id                          */
    void                   *PKEYD_pvData;                               /*  私有数据                    */
} __PX_KEY_DATA;

/*********************************************************************************************************
  posix 获取线程数据结构
*********************************************************************************************************/

__PX_CONTEXT   *_posixCtxGet(PLW_CLASS_TCB   ptcb);
__PX_CONTEXT   *_posixCtxTryGet(PLW_CLASS_TCB   ptcb);

/*********************************************************************************************************
  posix 获取进程数据结构
*********************************************************************************************************/

__PX_VPROC_CONTEXT  *_posixVprocCtxGet(VOID);

/*********************************************************************************************************
  名字结构
*********************************************************************************************************/
#define __PX_NAMED_OBJECT_SEM           0x00                            /*  posix 信号类型              */
#define __PX_NAMED_OBJECT_MQ            0x01                            /*  posix 消息队列              */

typedef struct {
    LW_LIST_LINE     PXNODE_lineManage;                                 /*  双向管理链表                */
    atomic_t         PXNODE_atomic;                                     /*  使用计数器                  */
    void            *PXNODE_pvData;                                     /*  保存的数据                  */
    int              PXNODE_iType;                                      /*  对象类型                    */
    char            *PXNODE_pcName;                                     /*  对象名                      */
} __PX_NAME_NODE;

#define PX_NAME_NODE_INITIALIZER        {{LW_NULL, LW_NULL}, {0}, LW_NULL, LW_NULL}

extern LW_OBJECT_HANDLE        _G_ulPosixLock;

#define __PX_LOCK()            API_SemaphoreMPend(_G_ulPosixLock, LW_OPTION_WAIT_INFINITE)
#define __PX_UNLOCK()          API_SemaphoreMPost(_G_ulPosixLock)

/*********************************************************************************************************
  名字节点操作
*********************************************************************************************************/
#define __PX_NAME_NODE_HASH_SIZE    17                                  /*  查询 hash 表大小            */

__PX_NAME_NODE  *__pxnameSeach(CPCHAR  pcName, INT  iHash);
INT              __pxnameAdd(__PX_NAME_NODE  *pxnode);
INT              __pxnameDel(CPCHAR  pcName);
INT              __pxnameDelByNode(__PX_NAME_NODE  *pxnode);
INT              __pxnameGet(CPCHAR  pcName, PVOID  *ppvData);

#endif                                                                  /*  LW_CFG_POSIX_EN > 0         */
#endif                                                                  /*  __POSIXLIB_H                */
/*********************************************************************************************************
  END
*********************************************************************************************************/
