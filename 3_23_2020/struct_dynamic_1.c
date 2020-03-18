#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct _iArray{
    int32_t* Data; //As you can see, it's a pointer, you can use it as an array. this will be our main array where we store our data.
    uint32_t Dimension; //size of the array
    uint32_t Usage; //index of the array
}iArray;

// Initializing the array with size, and as we are going to dynamically allocate, thus, we may use variable size.
bool iArray_Init(iArray* const pA, uint32_t Size){

    if(pA == NULL) return false;
    pA->Data = calloc(Size, sizeof(int32_t));
    if (pA->Data == NULL){
        //the check for whether calloc/malloc worked or not.
        pA->Dimension = pA->Usage = 0;
        return false;
    }
    pA->Dimension = Size;
    pA->Usage = 0;
    return true;
}
// if we want to append anything to the array.
bool iArray_Append(iArray* const pA, int32_t Elem) {
    if ( pA == NULL || //rejects insertion if array is full.
        pA->Dimension == pA->Usage) {
        return false;
    }
    pA->Data[pA->Usage] = Elem;     //Usage is the index of the array.
    pA->Usage++;   
    return true;
}

// This is a better implementation of append
bool better_iArray_Append(iArray* const pA, int32_t Elem) {
    if ( pA == NULL ) return false;
    if ( pA->Dimension == pA->Usage) { //checks whether array is full or not.
        int32_t *temp = realloc(pA->Data, 2 * pA->Dimension); //if we don't have enough space, we just allocate more space so we don't have too much trouble.
        if ( pA->Data == NULL ) {
            return false;
        }
    pA->Data = temp;
    pA->Dimension = 2 * pA->Dimension;
    } //we are doubling the size of the array.
    pA->Data[pA->Usage] = Elem;
    pA->Usage++;
    return true;
}

/** Makes a duplicate of an existing iArray object.
* Pre:
* pA points to a correctly-initialized iArray object
* Post:
* A new iArray object has been created such that:
* - Data[] duplicates the content and dimension of
* the original
* - Usage and Dimension equal the original
* - no memory is shared between the two iArray objects
* Returns:
* Pointer to the new iArray object; NULL if it could not
* be created.
*/
iArray* iArray_Copy(iArray* const pA) {
    if ( pA == NULL ) return NULL;  //mandatory checking whether the sent array is null or not.
    iArray* pCpy = calloc(1, sizeof(iArray)); //creating a new array. 
    if ( pCpy == NULL ) return NULL;    // mandatory checking
    pCpy->Data = calloc(pA->Dimension, sizeof(int32_t));    //we are allocating memory for the Data
    if ( pCpy->Data == NULL ) {
        free( pCpy );
        return NULL;
    }
    for(int i = 0 ; i < pA->Usage; i++){
        pCpy->Data[i] = pA->Data[i];    //Okay, so the slides do memcpy. I tried that, but for some reaosn, it wasn't working. Honestly, I don't know why it's not working. So when you do it in the assignment, please do it like this and avoid memcpy. I also saw one of the students facing the same trouble and changing the memcpy worked.
    }
    pCpy->Dimension = pA->Dimension;
    pCpy->Usage = pA->Usage;
    return pCpy;
}

void iArray_print(iArray A){
    printf("Printing array:\n");
    for(int i = 0; i < A.Usage; i++){
        printf("A[%d] = %d\n", i, A.Data[i]);
    }
}

int main(){
    iArray A;
    iArray_Init(&A, 1);
    iArray_Append(&A, 1);
    iArray_print(A);
    better_iArray_Append(&A, 2);
    iArray_print(A);
    iArray *B = iArray_Copy(&A);
    iArray_print(*B);
    better_iArray_Append(&A, 3);
    better_iArray_Append(B, 4);
    iArray_print(A);
    iArray_print(*B);
    return 0;
}