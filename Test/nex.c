#include <stdio.h>

int nextDigit(int N){
    static int divisor = 1; 
    printf("%d\n", divisor);
    if ( N / divisor == 0)
        return -1;
    int digit = ( N / divisor ) % 10; 
    divisor = 10 * divisor;
    return digit; 
}

int main(){
    int N = -2500568;
    int digit;
    while ( ( digit = nextDigit(N)) >= 0) {
        printf("%d\n", digit);
    }
    return 0;
}