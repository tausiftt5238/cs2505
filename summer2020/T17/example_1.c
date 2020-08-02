#include <stdio.h>

bool isMultOf4(int32_t Value) {

   uint32_t Mask = 0x00000003;  // 0000 0000 . . . 0000 0011

   int32_t low2bits = Value & Mask;

   return low2Bits == 0x0;
}


int main(){
    // isMultOf4() will return 1 if it is, otherwise 0. give it a try.
    return 0;
}