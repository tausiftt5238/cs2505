#ifndef FILTERDIGITS_H
#define FILTERDIGITS_H
#include <inttypes.h>

// DO NOT MODIFY THIS FILE IN ANY WAY!! //

// Rather than use a nondescriptive label, or none at all, we will use
// an enumerated type to make the logic of of the code clearer:
enum FilterAction {HIFIRST, LOFIRST};

/**  Computes a new integer from N by separating all digits of N that
 *   are smaller than a specified value from those that are larger, and 
 *   placing the sets of digits (less, equal, larger) in an order 
 *   specified by one of the FilterAction values. 
 * 
 * For example:
 * 
 *     {954645,  LOFIRST,  6}  -->   544596
 *     {954645,  HIFIRST,  6}  -->   965445
 *     {   333,  LOFIRST,  3}  -->      333
 *     {   333,  HIFIRST,  3}  -->      333
 * 
 * Pre:  N is initialized
 *       action is HIFIRST or LOFIRST
 *       target is between 0 and 9, inclusive
 * Returns:  integer obtained by separating the digits of N as described
 *
 * Restrictions:
 *   - uses only its parameters and local automatic variables
 *     (i.e., no global variables)
 *   - does not make any use of character variables
 *   - does not make any use of arrays
 *   - does not read input or write output
 */
uint32_t FilterDigits(uint32_t N, enum FilterAction action, uint8_t pivot);

#endif
