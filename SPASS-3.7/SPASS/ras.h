/**************************************************************/
/* ********************************************************** */
/* *                                                        * */
/* *             RANDOM ACCESS STACK                        * */
/* *                                                        * */
/* *  $Module:   RAS                                        * */ 
/* *                                                        * */
/* *  Copyright (C) 1999, 2000, 2001 MPI fuer Informatik    * */
/* *                                                        * */
/* *  This program is free software; you can redistribute   * */
/* *  it and/or modify it under the terms of the FreeBSD    * */
/* *  Licence.                                              * */
/* *                                                        * */
/* *  This program is distributed in the hope that it will  * */
/* *  be useful, but WITHOUT ANY WARRANTY; without even     * */
/* *  the implied warranty of MERCHANTABILITY or FITNESS    * */
/* *  FOR A PARTICULAR PURPOSE.  See the LICENCE file       * */ 
/* *  for more details.                                     * */
/* *                                                        * */
/* *                                                        * */
/* $Revision: 1.2 $                                     * */
/* $State: Exp $                                            * */
/* $Date: 2010-02-22 14:09:58 $                             * */
/* $Author: weidenb $                                         * */
/* *                                                        * */
/* *             Contact:                                   * */
/* *             Christoph Weidenbach                       * */
/* *             MPI fuer Informatik                        * */
/* *             Stuhlsatzenhausweg 85                      * */
/* *             66123 Saarbruecken                         * */
/* *             Email: spass@mpi-inf.mpg.de                * */
/* *             Germany                                    * */
/* *                                                        * */
/* ********************************************************** */
/**************************************************************/

#ifndef _RAS_
#define _RAS_


/**************************************************************/
/* Includes                                                   */
/**************************************************************/

#include "misc.h"
#include "memory.h"


/**************************************************************/
/* Constants and types                                        */
/**************************************************************/

#define ras_alloc   -1  /* index of size of allocated space */
#define ras_top     -2  /* index of next free element */
#define ras_head     2  /* size of stack head for management purposes */
#define ras_stdsize 16  /* standard stack size */


typedef POINTER *RAS;

/* A RAS (Random Access Stack) is a pointer to an array of elements */
/* where the actual size of the stack and its current top pointer   */
/* are stored one and two cells before the array pointer.           */


/**************************************************************/
/* Functions                                                  */
/**************************************************************/

RAS ras_InitWithSize(RAS ras, int size);

/**************************************************************/
/* Inline Functions                                           */
/**************************************************************/

static __inline__ RAS ras_CreateWithSize(int size)
/****************************************************************
  INPUT:   The maximal expected size of the stack to create.
  RETURNS: A new empty stack.
*****************************************************************/
{
  RAS result;

#ifdef CHECK
  if (size <= 0) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_CreateWithSize: size not positive.");
    misc_FinishErrorReport();
  }
#endif

  result            = (RAS) memory_Malloc((size + ras_head) * sizeof(POINTER));
  result            = result + ras_head;  /* leave space for head */
  result[ras_alloc] = (POINTER) size;
  result[ras_top]   = (POINTER) 0;
  return result;
}


static __inline__ RAS ras_Create(void)
{
  return ras_CreateWithSize(ras_stdsize);
}


static __inline__ void ras_Free(RAS ras)
{
  if (ras != NULL) {
    memory_Free (
      ras - ras_head,
      (ras_head + (int) ras[ras_alloc]) * sizeof(POINTER)
    );
  }
}

static __inline__ RAS ras_Init(RAS ras)
/****************************************************************
  INPUT:   A random access stack.
  RETURNS: The initialized and potentially new stack.
  CAUTION: Because it potentially frees the old stack this
           function must be called inside an assignment like:
              stack = ras_InitWithSize(stack, ...)
*****************************************************************/
{
  return ras_InitWithSize(ras, ras_stdsize);
}


static __inline__ int ras_Size(RAS ras)
{
  return (int) ras[ras_top];
}


static __inline__ RAS ras_FastPush(RAS ras, POINTER entry)
/*********************************************************
  INPUT:   A random access stack and an element to push.
  RETURNS: The modified stack.
  CAUTION: The function does not care about stack overflow!
**********************************************************/    
{
  int top;

#ifdef CHECK
  if (ras_Size(ras) == (int) ras[ras_alloc]) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_FastPush: stack overflow.");
    misc_FinishErrorReport();
  }
#endif

  top          = ras_Size(ras);
  ras[top++]   = entry;
  ras[ras_top] = (POINTER) top;
  return ras;
}


static __inline__ RAS ras_Push(RAS ras, POINTER entry)
/*********************************************************
  INPUT:   A random access stack and an element to push.
  RETURNS: The modified and potentially new stack.
  SUMMARY: Before the push the stack is checked for overflow
           and in case of overflow its size is doubled while
           elements are copied to the (new) stack.
  CAUTION: Must be called inside an assignment:
              stack = ras_Push(stack, ...)
**********************************************************/  
{
  RAS old;
  int oldsize;
  POINTER *oldscan, *scan;

  /* if not enough space allocated, double it: */
  if (ras_Size(ras) == (int) ras[ras_alloc]) {
    old          = ras;
    oldsize      = (int) old[ras_alloc];
    ras          = ras_CreateWithSize(oldsize * 2);
    ras[ras_top] = (POINTER) oldsize;

    /* copy entries: */
    for (oldscan = old + oldsize - 1,scan = ras + oldsize - 1; oldscan >= old;
        oldscan--, scan--)
      *scan = *oldscan;

    ras_Free(old);
  }

  return ras_FastPush(ras, entry);
}


static __inline__ BOOL ras_LegalIndex(RAS ras, int stack_index)
{
  return 0 <= stack_index && stack_index < ras_Size(ras);
}


static __inline__ POINTER ras_Get(RAS ras, int stack_index)
{
#ifdef CHECK
  if (!ras_LegalIndex(ras, stack_index)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_Get: illegal stack index.");
    misc_FinishErrorReport();
  }
#endif

  return ras[stack_index];
}


static __inline__ RAS ras_Set(RAS ras, int stack_index, POINTER entry)
{
#ifdef CHECK
  if (!ras_LegalIndex(ras, stack_index)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_Set: illegal stack index.");
    misc_FinishErrorReport();
  }
#endif

  ras[stack_index] = entry;
  return ras;
}


static __inline__ BOOL ras_Empty(RAS ras)
{
  return ras_Size(ras) == 0;
}


static __inline__ POINTER ras_Pop(RAS ras)
{
  int top;

#ifdef CHECK
  if (ras_Empty(ras)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_Pop: empty stack.");
    misc_FinishErrorReport();
  }
#endif

  top          = ras_Size(ras) - 1;
  ras[ras_top] = (POINTER) top;
  return ras[top];
}


static __inline__ POINTER ras_Top(RAS ras)
{
#ifdef CHECK
  if (ras_Empty(ras)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In ras_Top: empty stack.");
    misc_FinishErrorReport();
  }
#endif

  return ras[ras_Size(ras) - 1];
}


#endif

