#include <stdio.h>
#include <math.h>   // this function is needed when you want to use math functions such as sqrt() in this example.

int main() {


   printf("  x   sqrt(x)\n");
   printf("-------------\n");

   for (int i = 2; i < 20; i++) {
       
       printf("%3d%10.4f\n", i, sqrt(i));
   }
   
   return 0;
}
