#include <stdio.h>

int Power(int X, int N) {

    int Result = 1;
    while (N-- > 0) {
      Result = Result * X;
    }
    return Result;
}


int main(){

    int Exp  = 10;
    int Base =  4;

    int BaseToExp = Power(Base, Exp);

    printf("%d ^ %d = %d\n", 
       Base,             // still 4 
       Exp,              // still 10
       BaseToExp);

    return 0;
}