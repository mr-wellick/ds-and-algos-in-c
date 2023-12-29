#include "graphs.h"
#include <stdio.h>

#define STRINGS 6
#define SEMITONES 22

int main(void) {
  Edge graph[STRINGS][SEMITONES] = {[5][8] = {10}};

  printf("We go from 8 to %d\n", graph[5][8].to);

  return 0;
}
