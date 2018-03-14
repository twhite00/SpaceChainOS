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
** 文   件   名: mp_cfg.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2007 年 04 月 10 日
**
** 描        述: 这是系统多处理器配置文件 (支持 SMP 或 AMP 系统)。
**
** 注        意: SylixOS 支持(或计划支持)两种并行计算机制: 
                 1: 紧耦合多处理器的(SMP)  eg. intel: dual core, ARM MPCore, ...
                 2: 消息传递接口 Message Passing Interface  (MPI) 并行计算体系.
                 
                 前者将所有物理共享存储器的 CPU 核抽象成一个逻辑上存在的核. 使得单核程序可以迅速移植到
                 多核系统, 对于用户而言, 系统仅存在一个逻辑上的 CPU, 所有的物理 CPU 统一由操作系统进行分配
                 并且维持实时调度与负载平衡.
                 
                 后者仅为一种并行程序设计思想接口, 与具体的硬件可以脱离, 例如 RTEMS 系统的多核支持. 
                 利用 MPI 可以设计出大型复杂并行计算群, 从而提高计算机集群计算能力. (SylixOS 可以应用
                 这项技术完成集群数据库计算)
                 
                 例如: 有些 MIPS 处理器为 32 核, 我们可以将 16 个核作为 SMP 运行一套 SylixOS 镜像.
                       另外 16 个核作为另一个 SMP 系统运行另一套 SylixOS 镜像, 两个 SMP 系统的两套 SylixOS
                       镜像可以组成一个 AMP (松耦合多处理器) 系统, 使用 MPI 进行通信.
*********************************************************************************************************/

#ifndef  __MP_CFG_H
#define  __MP_CFG_H

/*********************************************************************************************************
*                   是否需要系统对 SMP MULTI-PROCESSOR 支持 (紧耦合多处理器系统)
*
*  注  意  : SMP 同构多处理器支持, 将多核处理器在应用层面抽象为一个逻辑单核接口.
*********************************************************************************************************/

#define LW_CFG_SMP_EN                   1               /*  是否需要系统对多处理器支持                  */
#define LW_CFG_SMP_CPU_DOWN_EN          0               /*  是否支持动态关闭 CPU (不推荐使用)           */
#define LW_CFG_MAX_PROCESSORS           32              /*  系统支持 SMP 处理器最大个数, 1 ~ 2048       */

/*********************************************************************************************************
*                   是否需要系统对 MPI 接口 MULTI-PROCESSOR 支持 (并行分布式系统)
*
*  注  意  : MPI 多操作系统并行计算系统通信层抽象
*********************************************************************************************************/

#define LW_CFG_MPI_EN                   1               /*  并行分布式计算系统支持                      */
#define LW_CFG_PROCESSOR_NUMBER         1               /*  当前 MPI 处理器号                           */
#define LW_CFG_MAX_MPDPMAS              2               /*  系统双通道 RAM 缓冲区个数         < 65535   */

#endif                                                  /*  __MP_CFG_H                                  */
/*********************************************************************************************************
  END
*********************************************************************************************************/
