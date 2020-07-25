double* createArray_good(int Sz) {

   double *p = malloc( Sz * sizeof(double));

   if ( p != NULL ) {
      for (int idx = 0; idx < Sz; idx++)
         p[idx] = 0.0;
   }

   return p;	// ownership goes to caller
}

int* F_bad() {      // NEVER DO THIS!
	
   int Local = rand() % 1000;

   // Local ceases to exist when F()
   // executes its return, since Local has
   // automatic storage duration.

   return &Local;
}
