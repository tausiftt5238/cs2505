int main() {

   int  x = 42, y = 99;

   int*  p1 = &x;    // p1 stores address of variable x
   int*  p2 = &y;    // p2 stores address of variable y

   int** p3 = &p2;   // p3 stores address of variable p2

   int aa = *p1;     // aa stores value of the target of p1, 42
   *p1 = 10;         // the target of p1, which is x, stores 10

   int bb = **p3;    // bb stores value of the target of the
                     //    target of p3; p3 points to p1 and
                     //    p1 points to x, so bb gets value 99
   return 0;
}
