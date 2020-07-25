typedef struct _Location {        // declare type globally
   int X, Y;
} Location;

int main() {

   Location A;   // declare variable of type Location
   A.X = 5;             // set its data members
   A.Y = 6;

   Location B;   // declare another Location variable
   B = A;               // copy members of A into B
   return 0;
}
