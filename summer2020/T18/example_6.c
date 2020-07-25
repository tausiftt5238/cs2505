#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct _Rational {
   int32_t Top;
   int32_t Bottom;
};
typedef struct _Rational Rational;

/**
 *   Compute the sum of Left and Right.
 *   Pre:
 *        *Left and *Right have been properly initialized.
 *   Returns:
 *        A pointer to a Rational object equal to *Left + *Right.
 */
Rational* Rational_Add_w_return(const Rational* Left, const Rational* Right) {

   Rational *Sum = malloc(sizeof(Rational));

   Sum->Top    = Left->Top * Right->Bottom + 
                 Left->Bottom * Right->Top;
   Sum->Bottom = Left->Bottom * Right->Bottom;
   // Rational_Normalize(Sum);

   return Sum;
}

void Rational_Add_wo_return(Rational* const pSum, const Rational Left,
                                        const Rational Right) {

   pSum->Top    = Left.Top * Right.Bottom + 
                  Left.Bottom * Right.Top;

   pSum->Bottom = Left.Bottom * Right.Bottom;

   // Rational_Normalize(pSum);
}


int main(){
    Rational First, Second;
    First.Top = 1; First.Bottom = 2;
    Second.Top = 1; Second.Bottom = 3;
    Rational *Sum = Rational_Add_w_return(&First, &Second);  
    Rational_Add_wo_return(Sum, First, Second);
    return 0;
}