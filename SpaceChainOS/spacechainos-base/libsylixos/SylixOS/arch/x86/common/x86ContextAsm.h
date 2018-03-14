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
** 文   件   名: x86ContextAsm.h
**
** 创   建   人: Jiao.JinXing (焦进星)
**
** 文件创建日期: 2016 年 07 月 04 日
**
** 描        述: x86 体系构架上下文切换.
*********************************************************************************************************/

#ifndef __ARCH_X86CONTEXTASM_H
#define __ARCH_X86CONTEXTASM_H

/*********************************************************************************************************
  头文件
*********************************************************************************************************/

#include "arch/x86/arch_regs.h"
#include "x86Segment.h"

/*********************************************************************************************************

    +-----------------+
    |     EFLAGS      |
    +-----------------+
    |       CS        |
    +-----------------+
    |       EIP       |
    +-----------------+
    |      ERROR      |
    +-----------------+
    |       EBP       |
    +-----------------+
    |       EDI       |
    +-----------------+
    |       ESI       |
    +-----------------+
    |       EDX       |
    +-----------------+
    |       ECX       |
    +-----------------+
    |       EBX       |
    +-----------------+
    |       EAX       |
    +-----------------+
    |       PAD(2)    |
    +-----------------+
    |       SS(2)     |
    +-----------------+
    |       DS(2)     |
    +-----------------+
    |       ES(2)     |
    +-----------------+
    |       FS(2)     |
    +-----------------+
    |       GS(2)     |
    +-----------------+

*********************************************************************************************************/

#define __SAVE_SEG_REG  0                                               /*  不保存段寄存器              */

/*********************************************************************************************************
  上下文恢复
*********************************************************************************************************/

MACRO_DEF(RESTORE_REGS)
#if __SAVE_SEG_REG > 0
    MOVW    0(%ESP)  , %GS
    MOVW    2(%ESP)  , %FS
    MOVW    4(%ESP)  , %ES
    MOVW    6(%ESP)  , %DS
    MOVW    8(%ESP)  , %SS
#endif                                                                  /*  __SAVE_SEG_REG > 0          */
    ADDL    $(3 * 4) , %ESP

    MOVL    0(%ESP)  , %EAX
    MOVL    4(%ESP)  , %EBX
    MOVL    8(%ESP)  , %ECX
    MOVL    12(%ESP) , %EDX
    MOVL    16(%ESP) , %ESI
    MOVL    20(%ESP) , %EDI
    MOVL    24(%ESP) , %EBP
    ADDL    $(8 * 4) , %ESP                                             /*  不弹出 ERROR CODE           */

    IRET                                                                /*  IRET 等于弹出 CS EIP EFLAGS */
    MACRO_END()

/*********************************************************************************************************
  上下文保存
*********************************************************************************************************/

MACRO_DEF(SAVE_REGS)
    PUSHF                                                               /*  PUSH EFLAGS                 */

    SUBL    $(10 * 4) , %ESP
    MOVL    %EAX , 0(%ESP)
    MOVL    %EBX , 4(%ESP)
    MOVL    %ECX , 8(%ESP)
    MOVL    %EDX , 12(%ESP)
    MOVL    %ESI , 16(%ESP)
    MOVL    %EDI , 20(%ESP)
    MOVL    %EBP , 24(%ESP)

    MOVL    $0   , 28(%ESP)
    MOVL    $archResumePc , 32(%ESP)
    MOVW    %CS  , 36(%ESP)

    SUBL    $(3 * 4) , %ESP
#if __SAVE_SEG_REG > 0
    MOVW    %GS , 0(%ESP)
    MOVW    %FS , 2(%ESP)
    MOVW    %ES , 4(%ESP)
    MOVW    %DS , 6(%ESP)
    MOVW    %SS , 8(%ESP)
#endif                                                                  /*  __SAVE_SEG_REG > 0          */
    MACRO_END()

/*********************************************************************************************************
  异常/中断上下文保存
*********************************************************************************************************/

MACRO_DEF(INT_SAVE_REGS_HW_ERRNO)
    CLI
                                                                        /*  EFLAGS CS EIP ERRNO 已经PUSH*/
    SUBL    $(7 * 4) , %ESP
    MOVL    %EAX , 0(%ESP)
    MOVL    %EBX , 4(%ESP)
    MOVL    %ECX , 8(%ESP)
    MOVL    %EDX , 12(%ESP)
    MOVL    %ESI , 16(%ESP)
    MOVL    %EDI , 20(%ESP)
    MOVL    %EBP , 24(%ESP)

    SUBL    $(3 * 4) , %ESP
#if __SAVE_SEG_REG > 0
    MOVW    %GS , 0(%ESP)
    MOVW    %FS , 2(%ESP)
    MOVW    %ES , 4(%ESP)
    MOVW    %DS , 6(%ESP)
    MOVW    %SS , 8(%ESP)
#endif                                                                  /*  __SAVE_SEG_REG > 0          */
    MACRO_END()

/*********************************************************************************************************
  异常/中断上下文保存
*********************************************************************************************************/

MACRO_DEF(INT_SAVE_REGS_FAKE_ERRNO)
    CLI

    PUSHL   $0                                                          /*  PUSH FAKE ERROR CODE        */

    INT_SAVE_REGS_HW_ERRNO
    MACRO_END()

#endif                                                                  /*  __ARCH_X86CONTEXTASM_H      */
/*********************************************************************************************************
  END
*********************************************************************************************************/
