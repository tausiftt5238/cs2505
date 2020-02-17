#include "FilterDigits.h"

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
uint32_t FilterDigits(uint32_t N, enum FilterAction action, uint8_t pivot) {
   
   // complete implementation here...
   int position = 1;
	uint32_t right = 0;
	uint32_t middle = 0;
	uint32_t left = 0;
	if (action == LOFIRST)
	{
		// building right
		uint32_t temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check > pivot)
			{
				right += check * position;
				position *= 10;
				printf("Right: %d\n", right);
			}
			temp /= 10;
		}
		//building middle
		temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check == pivot)
			{
				middle += check * position;
				position *= 10;
				printf("middle: %d\n", middle);
			}
			temp /= 10;
		}
		//building left
		temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check < pivot)
			{
				left += check * position;
				position *= 10;
				printf("left: %d\n", left);
			}
			temp /= 10;
		}
	}
	else
	{
		uint32_t temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check < pivot)
			{
				right += check * position;
				position *= 10;
				printf("Right: %d\n", right);
			}
			temp /= 10;
		}
		//building middle
		temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check == pivot)
			{
				middle += check * position;
				position *= 10;
				printf("middle: %d\n", middle);
			}
			temp /= 10;
		}
		//building left
		temp = N;
		while (temp)
		{
			int check = temp % 10;
			if (check > pivot)
			{
				left += check * position;
				position *= 10;
				printf("left: %d\n", left);
			}
			temp /= 10;
		}
	}
   return left+middle+right;
}
