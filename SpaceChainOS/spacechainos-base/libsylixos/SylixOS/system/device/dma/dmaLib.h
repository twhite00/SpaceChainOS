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
** 文   件   名: dmaLib.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2008 年 01 月 06 日
**
** 描        述: 通用 DMA 设备管理库.

** BUG:
2009.09.15  加入了对任务队列的同步限制.
*********************************************************************************************************/

#ifndef __DMALIB_H
#define __DMALIB_H

/*********************************************************************************************************
  DMA 功能裁剪控制
*********************************************************************************************************/
#if (LW_CFG_MAX_DMA_CHANNELS > 0) && (LW_CFG_DMA_EN > 0)

/*********************************************************************************************************
  DMA 控制节点相关类型定义
*********************************************************************************************************/
/*********************************************************************************************************
  DMA 传输控制节点
*********************************************************************************************************/

typedef struct {
    LW_LIST_RING            DMAN_ringManage;                            /*  双向管理链表                */
    BOOL                    DMAN_bDontFree;                             /*  是否释放内存                */
    LW_DMA_TRANSACTION      DMAN_pdmatMsg;                              /*  传输传输控制块              */
} __DMA_WAITNODE;
typedef __DMA_WAITNODE     *__PDMA_WAITNODE;

/*********************************************************************************************************
  DMA 通道控制块
*********************************************************************************************************/

typedef struct {
    PLW_LIST_RING           DMAC_pringHead;                             /*  传输控制链表头              */

    INT                     DMAC_iNodeCounter;                          /*  节点计数器, 调试使用        */
    INT                     DMAC_iMaxNode;                              /*  列队中可以存在的最多 NODE   */
                                                                        /*  当 dma job add 超过此数量时 */
                                                                        /*  将阻塞, 直到少于此值        */
    LW_OBJECT_HANDLE        DMAC_ulJobSync;                             /*  任务队列同步锁              */
    BOOL                    DMAC_bIsInFlush;                            /*  是否正在清除队列            */
    
    PLW_DMA_FUNCS           DMAC_pdmafuncs;                             /*  DMA 驱动程序                */
    size_t                  DMAC_stMaxDataBytes;                        /*  最大传输传输长度            */
} __DMA_CHANNEL;
typedef __DMA_CHANNEL      *__PDMA_CHANNEL;

/*********************************************************************************************************
  DMA 功能裁剪控制
*********************************************************************************************************/
#endif                                                                  /*  LW_CFG_MAX_DMA_CHANNELS > 0 */
                                                                        /*  LW_CFG_DMA_EN   > 0         */
#endif                                                                  /*  __DMALIB_H                  */
/*********************************************************************************************************
  END
*********************************************************************************************************/
