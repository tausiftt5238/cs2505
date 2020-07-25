#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct _iArray {
   int32_t*  Data;
   uint32_t  Dimension;
   uint32_t  Usage;
};
typedef struct _iArray iArray;

bool iArray_Init(iArray* const pA, uint32_t Size) {

   if ( pA == NULL ) return false;
   pA->Data = calloc(Size, sizeof(int32_t));
   if ( pA->Data == NULL ) {
      pA->Dimension = pA->Usage = 0;
      return false;
   } 
   pA->Dimension = Size;
   pA->Usage = 0;
   return true;
}

bool iArray_Append_v1(iArray* const pA, int32_t Elem) {

   if ( pA == NULL || 
        pA->Dimension == pA->Usage) {
      return false;
   }
   pA->Data[Usage] = Elem;
   pA->Usage++;
   return true;
}

bool iArray_Append_v2(iArray* const pA, int32_t Elem) {

   if ( pA == NULL ) return false; 

   if ( pA->Dimension == pA->Usage) {

      int32_t *temp = realloc(pA->Data, 2 * pA->Dimension);
      if ( pA->Data == NULL ) {
         return false;      
      }

      pA->Data = temp;
      pA->Dimension = 2 * pA->Dimension;
   }

   pA->Data[Usage] = Elem;
   pA->Usage++;
   return true;
}

iArray* iArray_Copy(iArray* const pA) {

   if ( pA == NULL ) return NULL; 

   iArray pCpy = calloc(1, sizeof(iArray));
   if ( pCpy == NULL ) return NULL;

   pCpy->Data = malloc(pA->Dimension * sizeof(int32_t));
   if ( pCpy->Data == NULL ) {
      free( pCpy );
      return NULL;
   }

   memcpy(pCpy->Data, pA->Data, pA->Usage);

   pCpy->Dimension = pA->Dimension;
   pCpy->Usage = pA->Usage;

   return pCpy;
}
