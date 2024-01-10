#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  StackItem *dummyStack = createStackItem(0);

  push(&dummyStack, 8);
  push(&dummyStack, 10);
  push(&dummyStack, 12);
  push(&dummyStack, 13);
  push(&dummyStack, 15);

  // 5
  printf("We start with %d items\n\n", dummyStack->count);

  while (dummyStack->count > 0) {
    StackItem *top = pop(&dummyStack);
    printf("The value of top is: %d and the new count is %d\n", top->vertex,
           dummyStack->count);
    free(top);
    top = NULL;
  }

  free(dummyStack);
  dummyStack = NULL;

  return 0;
}
