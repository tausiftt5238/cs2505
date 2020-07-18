#include <stdbool.h>

/**  Truncates a given C string at a given character.
 *   Pre:   *str is a null-terminated array
 *   Returns: true if string was terminated
*/
bool truncString(char* const str, char ch) {

   // Walk *str until ch is found or end of string is reached
   int idx = 0;

   while ( str[idx] != '\0' ) {

      if ( str[idx] == ch ) {
         str[idx] = '\0';
         return true;
      }
      idx++;
   }
 
   return false;
}
