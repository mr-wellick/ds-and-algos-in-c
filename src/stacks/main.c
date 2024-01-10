#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>
// #include <stdlib.h>

int main(void) {
  Node *dummyNode = createNode(0);

  push(&dummyNode, 8);
  push(&dummyNode, 10);
  push(&dummyNode, 12);
  push(&dummyNode, 13);
  push(&dummyNode, 15);

  // 5
  printf("We start with %d items\n\n", dummyNode->count);

  while (dummyNode->count > 0) {
    Node *top = pop(&dummyNode);
    printf("The value of top is: %d and the new count is %d\n", top->vertex,
           dummyNode->count);
    free(top);
    top = NULL;
  }

  free(dummyNode);
  dummyNode = NULL;

  return 0;
}
