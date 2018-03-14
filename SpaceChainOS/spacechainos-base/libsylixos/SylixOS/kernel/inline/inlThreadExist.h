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
** 文   件   名: inlThreadExist.h
**
** 创   建   人: Han.Hui (韩辉)
**
** 文件创建日期: 2006 年 12 月 20 日
**
** 描        述: 检查线程是否存在
*********************************************************************************************************/

#ifndef  __INLTHREADEXIST_H
#define  __INLTHREADEXIST_H

/*********************************************************************************************************
  _Thread_Exist 
  用于 thread var swtich 判断旧线程是否存在，所以 ptcb 一定是 _K_ptcbTCBCur, 
  所以只需判断 _K_ptcbTCBIdTable[usIndex] 是否存在
*********************************************************************************************************/

static LW_INLINE INT  _Thread_Exist (PLW_CLASS_TCB  ptcb)
{
    REGISTER UINT16    usIndex;
    
    usIndex = _ObjectGetIndex(ptcb->TCB_ulId);
    
    return  (_K_ptcbTCBIdTable[usIndex] != LW_NULL);
}

#endif                                                                  /*  __INLTHREADEXIST_H          */
/*********************************************************************************************************
  END
*********************************************************************************************************/
