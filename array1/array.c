#include <stdio.h>
#include <stdlib.h>

// Constants
const int ARR_LEN = 5;
const int PTR_LEN = 3 * ARR_LEN;

int printarray(int *array, int len) { 

  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}


int main(void) {

  // Variables
  int i, a[ARR_LEN], b[ARR_LEN];

  // Initialize arrays
  for (i = 0; i < ARR_LEN; i++) {
    a[i] = i;
    b[i] = ARR_LEN - i;
  }

  // Initialize a pointer to a chunk of memory
  int *p = malloc(sizeof(int) * PTR_LEN);
  for (i = 0; i < PTR_LEN; i++) {
    p[i] = i;
  }

  // Print arrays
  printarray(a, ARR_LEN);
  printarray(b, ARR_LEN);
  printarray(p, PTR_LEN);

  // Free pointer
  free(p);
  
  return 0;
}
