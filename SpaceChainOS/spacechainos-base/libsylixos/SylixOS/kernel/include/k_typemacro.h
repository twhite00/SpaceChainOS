/*********************************************************************************************************
**
**                                    中国软件开源组织
**
**                                   嵌入式实时操作系统
**
**                                       SylixLW_THREAD(TM)
**
**                               Copyright  All Rights Reserved
**
**--------------文件信息--------------------------------------------------------------------------------
**
** 文   件   名: k_typemacro.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2006 年 12 月 13 日
**
** 描        述: 这是系统类型宏定义。
*********************************************************************************************************/

#ifndef  __K_TYPEMACRO_H
#define  __K_TYPEMACRO_H

#ifndef  LW_API                                                         /*  声明系统API                 */
#define  LW_API
#endif

/*********************************************************************************************************
  SCHEDLER
*********************************************************************************************************/

#define  LW_SCHED_ACT_INTERRUPT         0x00                            /*  任务被中断激活而就绪        */
#define  LW_SCHED_ACT_OTHER             0x01                            /*  任务被其他情况激活          */

/*********************************************************************************************************
  TIMER
*********************************************************************************************************/

#define  LW_TYPE_TIMER_UNUSED           0                               /*  没有使用                    */
#define  LW_TYPE_TIMER_ITIMER           1                               /*  普通定时器                  */
#define  LW_TYPE_TIMER_HTIMER           2                               /*  高速定时器                  */

#define  LW_TIMER_STATUS_RUNNING        1                               /*  定时器已经运行              */
#define  LW_TIMER_STATUS_STOP           0                               /*  定时器没有运行              */

/*********************************************************************************************************
  EVENT
*********************************************************************************************************/

#define  LW_TYPE_EVENT_UNUSED           0                               /*  空事件                      */
#define  LW_TYPE_EVENT_MSGQUEUE         2                               /*  消息队列事件                */
#define  LW_TYPE_EVENT_SEMC             3                               /*  计数信号量                  */
#define  LW_TYPE_EVENT_SEMB             6                               /*  二进制信号量                */
#define  LW_TYPE_EVENT_SEMRW            1                               /*  读写信号量                  */
#define  LW_TYPE_EVENT_MUTEX            4                               /*  互斥信号量                  */
#define  LW_TYPE_EVENT_EVENTSET         5                               /*  事件标志组                  */

#define  LW_MASK_EVENT_RESOURCE         0x0000ffff                      /*  防死锁资源位 (未支持)       */

/*********************************************************************************************************
  THREAD STATUS
*********************************************************************************************************/

#define  LW_THREAD_STATUS_RDY           0x0000                          /*  任务就绪                    */
#define  LW_THREAD_STATUS_DELAY         0x0001                          /*  延迟                        */
#define  LW_THREAD_STATUS_SEM           0x0002                          /*  等待信号量                  */
#define  LW_THREAD_STATUS_MSGQUEUE      0x0004                          /*  等待数据队列                */
#define  LW_THREAD_STATUS_EVENTSET      0x0008                          /*  等待事件标志组              */
#define  LW_THREAD_STATUS_SIGNAL        0x0010                          /*  等待信号                    */
#define  LW_THREAD_STATUS_JOIN          0x0020                          /*  等待另外的线程 (信号不唤醒) */

#define  LW_THREAD_STATUS_PEND_ANY     (LW_THREAD_STATUS_SEM        |   \
                                        LW_THREAD_STATUS_MSGQUEUE   |   \
                                        LW_THREAD_STATUS_EVENTSET   |   \
                                        LW_THREAD_STATUS_SIGNAL)
                                        
/*********************************************************************************************************
  THREAD STATUS INTERNAL! (初始化的线程, 还没有得到执行)
*********************************************************************************************************/

#define  LW_THREAD_STATUS_INIT          0x0040                          /*  初始化                      */
                                        
/*********************************************************************************************************
  THREAD STATUS INTERNAL! (以下状态如果在 SMP 系统, 则需要请求设置)
*********************************************************************************************************/

#define  LW_THREAD_STATUS_SUSPEND       0x0080                          /*  任务被挂起                  */
                                                                        /*  就算收到信号也只能等待resume*/
                                                                        /*  才能运行信号句柄            */
                                                                        
#define  LW_THREAD_STATUS_STOP          0x0100                          /*  被发送信号任务强制停止      */

#define  LW_THREAD_STATUS_WDEATH        0x0200                          /*  僵死状态                    */

/*********************************************************************************************************
  THREAD STATUS INTERNAL! (以下状态如果在 SMP 系统, 等待目标线程 status 设置完成)
*********************************************************************************************************/

#define  LW_THREAD_STATUS_WSTAT         0x0400                          /*  等待设置完成                */

/*********************************************************************************************************
  TIME OUT FLAG
*********************************************************************************************************/

#ifdef   __SYLIXOS_KERNEL

#define  LW_WAIT_TIME_OUT                0x01                           /*  超时                        */
#define  LW_WAIT_TIME_CLEAR              0x00                           /*  清除超时标志位              */

/*********************************************************************************************************
  EVENT DELETE
*********************************************************************************************************/

#define  LW_EVENT_DELETE                 0x01                           /*  事件不存在                  */
#define  LW_EVENT_EXIST                  0x00                           /*  事件存在                    */

/*********************************************************************************************************
  HEAP SEGMENT MAGIC FLAG
*********************************************************************************************************/

#define  LW_SEG_MAGIC_REAL               0xffffffff

/*********************************************************************************************************
  PARTITION FLAG
*********************************************************************************************************/

#define  LW_PARTITION_UNUSED             0x00                           /*  没有使用                    */
#define  LW_PARTITION_USED               0xff                           /*  使用                        */

/*********************************************************************************************************
  RMS
*********************************************************************************************************/

#define  LW_RMS_UNUSED                   0x00
#define  LW_RMS_USED                     0xff

#define  LW_RMS_INACTIVE                 0x01                           /*  刚刚建立                    */
#define  LW_RMS_ACTIVE                   0x02                           /*  初始化了周期，测量执行时间  */
#define  LW_RMS_EXPIRED                  0x03                           /*  有任务阻塞了                */

/*********************************************************************************************************
  STACK AUTO ALLOC
*********************************************************************************************************/

#define  LW_STACK_AUTO_ALLOC             0xff                           /*  系统自动对栈开辟            */
#define  LW_STACK_MANUAL_ALLOC           0x00                           /*  手动开辟                    */

/*********************************************************************************************************
  信号相关 (调度器返回值)
*********************************************************************************************************/

#define  LW_SIGNAL_EINTR                 0x01                           /*  正常信号中断                */
#define  LW_SIGNAL_RESTART               0x02                           /*  SA_RESTART 属性信号中断     */
                                                                        /*  需要重启调用                */
#endif                                                                  /*  __SYLIXOS_KERNEL            */

#endif                                                                  /*  __K_TYPEMACRO_H             */
/*********************************************************************************************************
  END
*********************************************************************************************************/
