#include <stdio.h>
#include <stdint.h>

int32_t squeezeOutOdds(int32_t List[], uint32_t Usage);
int main(){
    int my_array[] = { 484, 501, 122, 777, 29, 24, 543, 204, 484, 122, 24, 204};    
    int size = 12;
    int new_size = squeezeOutOdds(my_array, size);
    for(int i = 0 ; i < new_size; i ++){
        printf("%d ", my_array[i]);
    }
    printf("\n");
    return 0;
}

// Takes an array of integers and removes all the odd ones,
// without altering the order of any of the even values.
//
// Pre:
//      List[] has dimension >= Usage
// Post:
//      All the even values are listed in successive cells at the
//      beginning of List[], in their original relative order.
// Returns:
//      the number of even values in the list
//
int32_t squeezeOutOdds(int32_t List[], uint32_t Usage) { 

   uint32_t Trailer = 0;
   // Move Trailer to first odd value, if any.
   while ( Trailer < Usage && List[Trailer] % 2 == 0 )
      ++Trailer;
   // Check for case there are no odd values in List[]
   if ( Trailer == Usage )
      return Trailer;
    uint32_t Leader = Trailer + 1;

   // Walk Leader to end of List[]
   while ( Leader < Usage ) {

      // If Leader is at an even value, move it forward; 
      //    advance Trailer
      if ( List[Leader] % 2 == 0 ) {
         List[Trailer] = List[Leader];
         ++Trailer;
      }

      // Always advance Leader
      ++Leader;
   }

   // When done, Trailer is one past the final even value,
   // so it equals the number of even values that are left.
   return Trailer;
}
