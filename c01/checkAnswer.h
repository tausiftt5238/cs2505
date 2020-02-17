#ifndef CHECKANSWER_H
#define CHECKANSWER_H
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include "FilterDigits.h"

// DO NOT MODIFY THIS FILE IN ANY WAY!! //

/**
 * 
 *  Pre:  fp is open on an output file
 *        origValue stores the original value of the integer being squeezed
 *        stuAnswer stores the result computed by the student's solution
 *        action is set the same value passed to the student's solution
 *  Returns:  true iff the stuAnswer matches the correct result
 */
bool checkAnswer(FILE* fp, uint32_t origValue, uint32_t stuAnswer, enum FilterAction action, uint8_t pivot);

#endif
