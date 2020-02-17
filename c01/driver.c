// CS 2505 Fall 2018
// Test driver for C01
//
// Invocation:   ./driver <test case file> <results file> [-repeat]
//
// Standard Library headers:
#include <stdio.h>             // for I/O functionality
#include <stdlib.h>            // for general features
#include <string.h>            // for C string library functionality
// "Local" headers:
#include "FilterDigits.h"      // for assigned function
#include "Generator.h"         // for test case generation
#include "checkAnswer.h"       // for grading functions

// Test driver for the FilterDigits() function.
// Invoke as:
//             ./driver <test case file> <results file> [-repeat]
//
// The driver calls a test-case generator, which creates an input file
// containing a fixed number of test cases.  Then, your version of the
// function FilterDigits() is applied to each test case, and the results
// are passed to a check tool.  The check tool uses a reference version
// of the function to compute the correct solution, and compare that to
// the results from your solution.
//
// The grading results are written to the file <results file>.txt.
//
// Without the -repeat switch, the code will generate random test data;
// if you use the switch, the date from the last previous test will be
// reused.
//
// You may modify this file as you like, but this version of the file
// will be used in testing your submission.

// The test case generator writes the cases to a file; this is the name
// used for that file:
char* testsFile = "TestCases.txt";

// We will expect the longest line in the input file to contain no more
// than 100 characters (which is generous in this case).
const uint32_t MAX_LINE_LENGTH = 101;

int main(int argc, char* argv[]) {
   
   // This program expects the user to supply his/her PID on the command
   // line, and optionally takes one switch (-repeat).  Therefore, it
   // checks for the presence of the correct number of parameters, and
   // exits with a diagnostic message if that is incorrect:
   if ( argc < 3 ) {
      printf("Invocation:  %s <test case file> <results file> [-repeat]\n", argv[0]);
      return 1;
   }
   
   // We will use the supplied names for the test case file and the results file:
   char* dataFile = argv[1];
   char* resultsFile = argv[2];
   bool  randomize = true;
   if ( argc == 4 && strcmp(argv[3], "-repeat") == 0 ) {
      randomize = false;
   }
   
   // Generate the specified input file:
   uint32_t nCases     = Generate(dataFile, randomize);
   uint32_t ptsPerCase = 10;
   uint32_t totalPts   = nCases * ptsPerCase;
   uint32_t totalScore = 0;
   
   // Attempt to open the specified input file; exit with a diagnostic
   // if it cannot be opened for reading:   
   FILE* tests = fopen(dataFile, "r");
   if ( tests == NULL ) {
      printf("Could not open input file: %s\n", dataFile);
      return 2; 
   }

   // Attempt to open the specified output file; exit with a diagnostic
   // if it cannot be opened for writing:   
   FILE* results = fopen(resultsFile, "w");
   if ( results == NULL ) {
      printf("Could not open output file: %s\n", resultsFile);
      fclose(tests);
      return 3;
   }
   // Write header to output file:
   fprintf(results, "OK?           Test Case                Response\n");
   fprintf(results, "-----------------------------------------------\n");
   
   char Line[MAX_LINE_LENGTH];         // holds the current input line
   char actionFlag[MAX_LINE_LENGTH];   // holds the current Action
   uint32_t N = 0,                     // holds the integer to be "filtered"
            filteredN = 0;             // holds the "squeezed" integer
   uint8_t  pivot = 0;                // holds the cap/floor value
   
   // The loop uses the read-to-input-failure pattern.  That is, we will
   // attempt to read the next expected input from the file, and then
   // validate that reading, before we attempt to process any data.
   //
   // In the loop test, we take advantage of the fact that fgets() will
   // return NULL If it fails to read any input.  That will force the
   // loop to terminate when the end of the input file is reached.
   while ( fgets(Line, MAX_LINE_LENGTH, tests) != NULL ) {
      
      // Try to read the actionFlag from the input line that was just
      // read into Line; sscanf() will return 0 if nothing was read.
      // In that case, write a diagnostic message, skip the remainder of
      // the loop body and look for another line of input.
      if ( sscanf(Line, "%s", actionFlag) != 1 ) {
         printf("Failed to read an actionFlag value from %s\n", Line);
         continue;
      }
      
      // Try to read an integer value from the input line that was just
      // read into Line.  Here, we encounter one limitation of sscanf();
      // it does not maintain any knowledge of previous calls, so it
      // resumes reading from the beginning of Line.  We could sidestep
      // that issue by reading both the actionFlag and the integer in a
      // single call to sscanf(); but that makes checking the results of
      // the two read operations clumsy.
      //
      // Instead, we take advantage of a C format specifier feature; if
      // we follows the '%' with an asterisk, a value is read and then
      // discarded.
      //
      // In this case we reread the action flag value but don't save it.
      if ( sscanf(Line, "%*s %"SCNu32" %"SCNu8, &N, &pivot) != 2 ) {
         printf("Failed to read an integer value from %s\n", Line);
         continue;
      }
      
      // Determine whether the actionFlag indicates we should squeeze
      // out the even digits, or the odd digits, or that there was
      // something wrong with the actionFlag.
      //
      // strcmp() compares two (C-style) character strings; it returns
      // zero if the strings match, something negative if the first
      // string precedes the second string, and something positive if
      // the first string follows the second string.
      enum FilterAction option;
      if ( strcmp(actionFlag, "HIFIRST") == 0 ) {
         option = HIFIRST;
      }
      else if ( strcmp(actionFlag, "LOFIRST") == 0 ) {
         option = LOFIRST;
      }
      else {
         fprintf(results, "Unrecognized action flag: %s\n", actionFlag);
         continue;
      }
      // Compute the answer computed by the student's solution:
      filteredN = FilterDigits(N, option, pivot);
      
      // Now, check the computed answer:
      if ( checkAnswer(results, N, filteredN, option, pivot) ) {
		  totalScore += ptsPerCase;
	  } 
   }

   // Write the total score to the results file:
   fprintf(results, "\nScore:  %3"PRIu32" / %3"PRIu32"\n", totalScore, totalPts);
   
   // It's important to explicitly close files when we are finished with
   // them, because:
   //   - the OS needs to know the files are no longer in use 
   //   - output written to a file is buffered and may not actually
   //     reach the file unless it is properly closed
   fclose(tests);
   fclose(results);
   
   // Traditionally, return 0 on successful termination.
   return 0;
}
