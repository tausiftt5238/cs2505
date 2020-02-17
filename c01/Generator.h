#ifndef GENERATOR_H
#define GENERATOR_H
#include <inttypes.h>
#include <stdbool.h>

// DO NOT MODIFY THIS FILE IN ANY WAY!! //

/**  Generate data for 20 test cases and write them to the specified file.
 * 
 *  Pre:  fName has been set to the desired name for the test case file
 *  Returns:  the number of test cases generated
 */
uint32_t Generate(const char* const fName, bool randomize);

#endif
