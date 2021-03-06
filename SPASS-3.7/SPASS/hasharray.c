/**************************************************************/
/* ********************************************************** */
/* *                                                        * */
/* *                       HASHING                          * */
/* *                                                        * */
/* *  $Module:   HASHARRAY                                  * */ 
/* *                                                        * */
/* *  Copyright (C) 1997, 1998, 2000, 2001                  * */
/* *  MPI fuer Informatik                                   * */
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
/* $Revision: 1.3 $                                         * */
/* $State: Exp $                                            * */
/* $Date: 2010-02-22 14:09:58 $                             * */
/* $Author: weidenb $                                       * */
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


/* $RCSfile: hasharray.c,v $ */

#include "hasharray.h"


/**************************************************************/
/* Functions                                                  */
/**************************************************************/

HASH hsh_Create(void)
/**************************************************************
  RETURNS: A new, empty hasharray
***************************************************************/
{
  HASH h;
  NAT  l;
  h = (LIST*) memory_Malloc(sizeof(LIST) * hsh__SIZE);
  for (l=0; l < hsh__SIZE; l++)
    h[l] = list_Nil();
  return h;
}

void hsh_Reset(HASH H)
/**************************************************************
  INPUT:   A hasharray
  EFFECT:  Deletes all information stored in the array but keeps
           the array itself.
           Keys and data items are not deleted !
***************************************************************/
{
  int  i;
  LIST Scan, Pair;
  for (i = 0; i < hsh__SIZE; i++) {
    for (Scan = H[i]; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
      Pair = list_Car(Scan);
      list_Delete(list_PairSecond(Pair));
      list_PairFree(Pair);
    }
    list_Delete(H[i]);
    H[i] = list_Nil();
  }
}

void hsh_Print(HASH H, void (*KeyPrint)(POINTER), void (*ValuePrint)(POINTER))
/**************************************************************
  INPUT:   A hasharray and a print function for the values
  EFFECT:  Prints all values in the hash array
***************************************************************/
{
  int  i;
  LIST Scan;
  
  for (i = 0; i < hsh__SIZE; i++) {
    Scan = H[i];
    printf("\n %d:",i);
    while (!list_Empty(Scan)) {
      KeyPrint(list_PairFirst(list_Car(Scan)));
      printf("-");
      ValuePrint(list_PairSecond(list_Car(Scan)));
      printf("\n   ");
      Scan = list_Cdr(Scan);
    }
  }
}

void hsh_Delete(HASH H)
/**************************************************************
  INPUT:   A hasharray
  EFFECT:  Deletes all information stored in the array and 
           the array itself.
           Keys and data items are not deleted !
***************************************************************/            
{
  hsh_Reset(H);
  memory_Free(H, sizeof(LIST) * hsh__SIZE);
}

LIST hsh_GetAllEntries(HASH H)
/**************************************************************
  INPUT:   A hasharray
  RETURNS: A new list of all data items stored in the hasharray
***************************************************************/
{
  LIST Scan, Result;
  NAT i;
  Result = list_Nil();
  for (i = 0; i < hsh__SIZE; i++) {
    for (Scan = H[i]; !list_Empty(Scan); Scan = list_Cdr(Scan))
      Result = list_Nconc(Result, list_Copy(list_PairSecond(list_Car(Scan))));
  }
  return Result;
}

LIST hsh_NGetAllKeyValueListPairs(HASH H)
/**************************************************************
  INPUT:   A hasharray
  RETURNS: A new list of all key valuelist pairs, where the
           key valuelist pairs are not copied
***************************************************************/
{
  LIST Result;
  NAT i;
  Result = list_Nil();
  for (i = 0; i < hsh__SIZE; i++) {
    if (!list_Empty(H[i]))
      Result = list_Nconc(list_Copy(H[i]), Result);
  }
  return Result;
}

void hsh_Check(HASH H)
/**************************************************************
  INPUT:   A hasharray
  EFFECT:  Traverses the whole array and the lists to find dangling pointers.
***************************************************************/
{
  LIST          Scan, Scan2, Pair;
  NAT           i;
  unsigned long Key;
  for (i = 0; i < hsh__SIZE; i++) {
    for (Scan = H[i]; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
      Pair = list_Car(Scan);
      Key = (unsigned long)list_PairFirst(Pair);
      for (Scan2 = list_PairSecond(Pair); !list_Empty(Scan2); Scan2 = list_Cdr(Scan2)) {
	POINTER Value;
	char Z;
	Value = list_Car(Scan2);
	Z = * ((char*) Value);
      }
    }
  }
}
