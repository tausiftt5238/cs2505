#include <stdlib.h> //needed for calloc()
#include <string.h>

/**  Makes a duplicate of a given C string.
 *   Pre:   *str is a null-terminated array
 *   Returns: pointer to duplicate of *str; NULL on failure
 *   Calls:  calloc()
 */

char* dupeString_wo_memcpy(const char* const str) {

   // Allocate array to hold duplicate, using calloc() to
   //    fill new array with zeroes; 
   //    return NULL if failure
   char* cpy = calloc(strlen(str) + 1, sizeof(char));
   if ( cpy == NULL ) return NULL;
   
   // Copy characters until terminator in *str is reached
   int idx = 0;
   while ( str[idx] != '\0' ) {
      cpy[idx] = str[idx];
      idx++;
   }

   return cpy;
}


/**  Makes a duplicate of a given C string.
 *   Pre:   *str is a null-terminated array
 *   Returns: pointer to duplicate of *str; NULL on failure
 *   Calls:  calloc(), memcpy()
 */
char* dupeString_w_memcpy(const char* const str) {

   // Allocate array to hold duplicate, using calloc() to
   //    fill new array with zeroes; 
   //    return NULL if failure
   char* cpy = calloc(strlen(str) + 1, sizeof(char));
   if ( cpy == NULL ) return NULL;
   
   // Use memcpy() to copy characters from *str to *cpy
   memcpy(cpy, str, strlen(str));

   return cpy;
}
