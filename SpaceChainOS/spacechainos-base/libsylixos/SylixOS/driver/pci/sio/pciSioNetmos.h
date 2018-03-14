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
** 文   件   名: pciSioNetmos.h
**
** 创   建   人: Lu.Zhenping (卢振平)
**
** 文件创建日期: 2016 年 06 月 12 日
**
** 描        述: PCI NETMOS 16c550 设备驱动.
*********************************************************************************************************/

#ifndef __PCISIONETMOS_H
#define __PCISIONETMOS_H

/*********************************************************************************************************
  设备名称前缀
*********************************************************************************************************/
#define PCI_SIO_NETMOS_TTY_PERFIX   "/dev/ttyPCI"
#define PCI_SIO_NETMOS_TTY_RBUF_SZ  256
#define PCI_SIO_NETMOS_TTY_SBUF_SZ  256

/*********************************************************************************************************
  函数声明
*********************************************************************************************************/
INT  pciSioNetmosInit(VOID);

#endif                                                                  /*  __PCISIONETMOS_H            */
/*********************************************************************************************************
  END
*********************************************************************************************************/
