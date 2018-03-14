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
** 文   件   名: kernel_cfg.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2006 年 12 月 12 日
**
** 描        述: 这是内核基本配置文件。
*********************************************************************************************************/

#ifndef __KERNEL_CFG_H
#define __KERNEL_CFG_H

/*********************************************************************************************************
*                                   编译器相关 (参数传递规则)
* 当不清楚编译器及CPU特性时, 请在这里定义 __EXCLIB_STDARG 宏, 表示需要外部 stdarg 库支持.
*********************************************************************************************************/

#define LW_CFG_ARG_STACK_GROWTH                 0       /*  0: C 函数调用, 连续参数存放地址递增         */
                                                        /*  1: C 函数调用, 连续参数存放地址递减         */
                                                        /*  例如 ARM ATPCS 标准参数压栈从右向左,而且堆栈*/
                                                        /*  增长方向向低地址, 所以参数的存放顺序地址递增*/
/*********************************************************************************************************
*                                   内核对象数量管理
*********************************************************************************************************/

#define LW_CFG_MAX_EVENTS                       3000    /*  系统使用事件的最大个数              < 65535 */
#define LW_CFG_MAX_EVENTSETS                    500     /*  系统使用事件集的最大个数            < 65535 */
#define LW_CFG_MAX_PARTITIONS                   50      /*  系统定长分区内存管理最大分区数      < 65535 */
#define LW_CFG_MAX_REGIONS                      50      /*  系统变长分区内存管理对大分区数      < 65535 */
#define LW_CFG_MAX_MSGQUEUES                    500     /*  系统消息队列最大个数                < 65535 */
#define LW_CFG_MAX_TIMERS                       50      /*  系统使用总定时器最大个数            < 65535 */
#define LW_CFG_MAX_THREADS                      500     /*  系统管理的最大线程数量，            < 65535 */
#define LW_CFG_MAX_RMSS                         32      /*  系统管理的最大精度单调调度器数量    < 65535 */
#define LW_CFG_MAX_INTER_SRC                    256     /*  系统使用中断向量表大小,中断源数量   <  9999 */
#define LW_CFG_MAX_NOTEPADS                     4       /*  系统每个线程使用的记事本数量        <   255 */
#define LW_CFG_MAX_THREAD_GLB_VARS              16      /*  系统总共需要使用的全局变量私有化个数< 65535 */

/*********************************************************************************************************
*                                   系统 LOGO
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_KERNEL_LOGO                      1       /*  是否提供系统 LOGO 图像字串变量              */

/*********************************************************************************************************
*                                   系统调试信息管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_ERRORMESSAGE_EN                  1       /*  是否允许将系统故障信息打印 (独立于任何服务) */
#define LW_CFG_LOGMESSAGE_EN                    1       /*  是否允许将系统运行状态打印 (独立于任何服务) */
#define LW_CFG_BUGMESSAGE_EN                    1       /*  是否允许将系统运行BUG打印  (独立于任何服务) */
#define LW_CFG_ERRORMESSAGE_DETAIL_EN           1       /*  是否需要打印详细错误信息                    */

/*********************************************************************************************************
*                                   系统中断测量接口
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_INTER_MEASURE_HOOK_EN            0       /*  是否允许系统中断测量接口 (不需要请关闭)     */

/*********************************************************************************************************
*                                   系统跟踪与监控管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_MONITOR_EN                       0       /*  是否允许系统提供监控信息                    */

/*********************************************************************************************************
*                                   CPU 特殊配置
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_CPU_EXC_HOOK_EN                  1       /*  是否允许 arch 提供异常处理回调供 bsp 使用   */

/*********************************************************************************************************
*                                   系统内核管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_ARG_CHK_EN                       1       /*  是否允许系统参数查错                        */
#define LW_CFG_CPU_HOOKS_EN                     1       /*  是否允许系统的钩子函数连接                  */
#define LW_CFG_SOFTWARE_WATCHDOG_EN             1       /*  是否允许任务软件看门狗功能 (任务级)         */
#define LW_CFG_OBJECT_NAME_SIZE                 32      /*  系统提供控件名字最大长度                    */
#define LW_CFG_OBJECT_SHARE_EN                  1       /*  是否允许内核与应用共享内核对象              */
#define LW_CFG_ERRORNO_AUTO_CLEAR               0       /*  是否在 API 正确时, 自动将 errno 清零        */
#define LW_CFG_PANIC_FUNC                       1       /*  0: panic 系统重新启动, 1: 当前任务挂起      */
#define LW_CFG_STK_EMPTY_FLAG                   0xab    /*  堆栈空闲区域填充字节内容(用于堆栈检查)      */
#define LW_CFG_SLICE_DEFAULT                    10      /*  系统默认的任务时间片 (ticks)                */

/*********************************************************************************************************
*                                   系统异常信息输出管理
*
* 依存关系: FIO
*********************************************************************************************************/

#define LW_CFG_ABORT_BASIC_INFO_EN              1       /*  基本异常信息打印                            */
#define LW_CFG_ABORT_CALLSTACK_INFO_EN          1       /*  异常调用栈信息打印                          */

/*********************************************************************************************************
*                                   线程操作功能管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_THREAD_CHANGE_PRIO_EN            1       /*  是否允许修改任务优先级                      */
#define	LW_CFG_THREAD_RESTART_EN                1       /*  是否允许任务重新启动                        */
#define LW_CFG_THREAD_DEL_EN                    1       /*  是否允许任务删除                            */
#define LW_CFG_THREAD_SUSPEND_EN                1       /*  是否允许任务挂起与解挂                      */
#define	LW_CFG_THREAD_NOTE_PAD_EN               1       /*  是否允许任务是用记事本功能                  */
#define LW_CFG_THREAD_SCHED_YIELD_EN            1       /*  是否允许使用 sched yield                    */
#define LW_CFG_THREAD_FORCE_SCHED_EN            1       /*  是否允许强制任务调度                        */
#define LW_CFG_THREAD_CPU_USAGE_CHK_EN          1       /*  是否允许系统内核确定每个任务CPU利用率       */
#define LW_CFG_THREAD_PRIVATE_VARS_EN           1       /*  是否允许系统提供全局资源私有化功能          */

/*********************************************************************************************************
*                                   线程取消功能管理
*
* 依存关系: 1: 线程删除
*********************************************************************************************************/

#define LW_CFG_THREAD_CANCEL_EN                 1       /*  是否允许线程支持类似 posix 标准的取消库     */
                                                        /*  THREAD_CANCEL 需要系统信号支持              */

/*********************************************************************************************************
*                                   类 POSIX 线程高级操作功能管理
*
* 依存关系: 1: 互斥信号量
            2: 二值信号量
*********************************************************************************************************/

#define LW_CFG_THREAD_EXT_EN                    1       /*  线程安全的单次运行支持                      */
                                                        /*  安全清除函数堆栈支持                        */
                                                        /*  条件变量支持                                */
                                                        /*  线程互斥量支持                              */

/*********************************************************************************************************
*                                   协程(纤程)操作功能管理
*
* 协同线程(windows 称之为: 纤程)类似多线程，每个线程都有有自己的堆栈,自己的局部变量。
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_COROUTINE_EN                     1       /*  系统是否提供协程支持                        */

/*********************************************************************************************************
*                                   计数型信号量管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_SEMC_EN                          1       /*  是否允许系统使用计数型信号量                */

/*********************************************************************************************************
*                                   二进制型信号量管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_SEMB_EN                          1       /*  是否允许二进制型信号量                      */

/*********************************************************************************************************
*                                   互斥型信号量管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_SEMM_EN                          1       /*  是否允许互斥型信号量                        */

/*********************************************************************************************************
*                                   读写信号量管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_SEMRW_EN                         1       /*  是否允许读写信号量                          */

/*********************************************************************************************************
*                                   消息队列管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_MSGQUEUE_EN                      1       /*  是否允许系统消息队列功能                    */

/*********************************************************************************************************
*                                   事件标志组管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_EVENTSET_EN                      1       /*  是否允许事件标志组                          */

/*********************************************************************************************************
*                                   定长分区内存管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_PARTITION_EN                     1       /*  是否允许定长分区内存管理                    */

/*********************************************************************************************************
*                                   变长分区内存管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_REGION_EN                        1       /*  是否允许动态变长分区内存管理                */

/*********************************************************************************************************
*                                   系统时间管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_TIME_TICK_HOOK_EN                1       /*   是否允许操作系统时钟挂钩                   */
#define LW_CFG_TIME_HIGH_RESOLUTION_EN          1       /*   提供获取高精度时间分辨率接口               */

/*********************************************************************************************************
*                                   内核定时器管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_HTIMER_EN                        1       /*   是否允许内核定时器工作                     */

/*********************************************************************************************************
*                                   任务级应用定时器管理
*
* 依存关系: 无
*********************************************************************************************************/

#define	LW_CFG_ITIMER_EN                        1       /*   是否允许任务级应用定时器工作               */
#define LW_CFG_ITIMER_OPTION                    LW_OPTION_THREAD_STK_CHK
                                                        /*   itimer 服务线程选项                        */
/*********************************************************************************************************
*                                   内核中断延迟处理工作队列管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_ISR_DEFER_EN                     1       /*  是否提供内核中断延迟处理工作队列管理        */
#define LW_CFG_ISR_DEFER_PER_CPU                0       /*  是否为每个 CPU 提供一个队列                 */
#define LW_CFG_ISR_DEFER_SIZE                   64      /*  每个中断延迟队列长度                        */
#define LW_CFG_ISR_DEFER_PRIO                   LW_PRIO_EXTREME
                                                        /*  中断延迟处理工作队列任务优先级              */
/*********************************************************************************************************
*                                   内核工作队列管理
*
* 依存关系: 1: 信号量
*********************************************************************************************************/

#define LW_CFG_WORKQUEUE_EN                     1       /*  是否提供内核工作队列服务                    */

/*********************************************************************************************************
*                                   进程资源回收任务
*
* 依存关系: loader
*********************************************************************************************************/

#define LW_CFG_RECLAIM_OPTION                   LW_OPTION_THREAD_STK_CHK
        
/*********************************************************************************************************
*                                   系统RTC管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_RTC_EN                           1       /*   是否允许使用操作系统RTC控制单元            */

/*********************************************************************************************************
*                                   系统精度单调调度器管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_RMS_EN                           1       /*   是否允许系统提供精度单调调度器服务         */

/*********************************************************************************************************
*                                   中断管理
*
* 依存关系: 无
*********************************************************************************************************/

#define LW_CFG_INTER_PRIO                       1       /*  是否支持中断优先级                          */
#define LW_CFG_INTER_TARGET                     1       /*  是否支持中断目标 CPU 设置                   */
#define LW_CFG_INTER_INFO                       1       /*  是否允许查询中断信息                        */
#define LW_CFG_INTER_FPU                        0       /*  是否允许内核 FPU kfpu=yes 需要使能此选项    */
                                                        /*  推荐为 0                                    */
                                                        
#include "cache_cfg.h"                                  /*  CACHE 配置文件                              */
#include "vmm_cfg.h"                                    /*  MMU 配置文件                                */
#include "memory_cfg.h"                                 /*  内存配置文件                                */
#include "endian_cfg.h"                                 /*  大小端配置文件                              */

#endif                                                  /*  __KERNEL_CFG_H                              */
/*********************************************************************************************************
  END
*********************************************************************************************************/
