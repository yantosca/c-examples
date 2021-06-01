#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"
//
// Main program
//
int main(void) {
  fizz_or_buzz();
  return 0;
}
//
// Subroutine
//
int fizz_or_buzz(void) {

  // Define a struct for the multiple & message (fizz or buzz)
  typedef struct Mult {
    int fac;
    char msg[5];
  } MultType;
  
  // Declare a variable of type struct Mult
  MultType multiples[] = {
    { 3, "Fizz " },
    { 5, "Buzz " },
    { 7, "Bang " }
  }; 

  // Variables
  int i, j, n;

  // Number of elements in multiples
  n = sizeof(multiples) / sizeof(MultType);

  // Make the output string only as long as needed
  char output[n * sizeof(multiples[0])];

  // Loop over numbers we want to print
  for (i = 1; i <= MAX_NUM; i++ ) {

    // Zero out the string
    output[0] = '\0';
    
    // Append the message for each multiple of
    // i to the output variable
    for (j = 0; j < n; j++) {
      if ( i % multiples[j].fac == 0 ) {
	strncat(output,
		multiples[j].msg,
		sizeof(multiples[j].msg)
		);
      }
    }

    // If the output string is not null, then
    // print the messages.  Otherwise print i.
    if ( output[0] != '\0' ) {
      printf("%s\n", output);
    } else {
      printf("%d\n", i);
    }
  }

  // Return success
  return 0;
}




