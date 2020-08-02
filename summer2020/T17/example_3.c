uint16_t flipBytes(uint16_t N) {
   
   uint16_t hiByte = N & 0xFF00;   // AND with 1111 1111 0000 0000

   hiByte = hiByte >> 8;           // shift hi byte to lower half;
                                   //   high bits are now 0000 0000
   
   N = N << 8;                     // shift lo byte to upper half
                                   //   low bits of N are now
                                   //   0000 0000

   N = N | hiByte;                 // combine the bytes;
                                   //    high bits of N remain same
                                   //    low bits are replaced with
                                   //       the low byte of hiByte
   
   return N;
}

uint16_t addNybbles(uint16_t N) {
   
   return ( (N & 0x000F) +            // get nybble 0

            ((N & 0x00F0) >>  4) +    // get nybble 1

            ((N & 0x0F00) >>  8) +    // get nybble 2

            ((N & 0xF000) >> 12) );   // get nybble 3
}

uint16_t zeroOddNybbles(uint16_t N) {
   
   if ( (N & 0x0001) != 0 ) {   // mask is: 0000 0000 0000 0001
      N = N & 0xFFF0;
   }
   
   if ( (N & 0x0010) != 0 ) {
      N = N & 0xFF0F;
   }
   
   if ( (N & 0x0100) != 0 ) {
      N = N & 0xF0FF;
   }
   
   if ( (N & 0x1000) != 0 ) {
      N = N & 0x0FFF;
   }
   
   return N;
}
