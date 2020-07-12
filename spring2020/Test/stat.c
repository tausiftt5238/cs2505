#include <stdio.h>

int Swap(int A, int B);
int W = 11;

int main(){
    int x = 53, y = 19;
    int sum = Swap(x,y);
    printf("%d %d %d\n", x,y,W);

    x += W;
    y += W;

    sum = Swap(x,y);
    printf("%d %d %d\n", x,y,W);

    return 0;
}

int Swap(int A, int B){
    int temp = B;
    A = B;
    B = temp; 
    W = A + B + W;
}