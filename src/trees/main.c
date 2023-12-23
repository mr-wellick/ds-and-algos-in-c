#include "trees.h"
#include <stdio.h>

int main(void) {
  // create BST and add values
  Node *root = NULL;
  /*      10
        /    \
       5      15
      / \     / \
    -5  N    N  20
    /\          /\
   N N         N  N */
  insert(&root, 10);
  insert(&root, 5);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, -5);
  insert(&root, 20);

  // pre-order traversal output: 10, 5, -5, 15, 20
  printTree(&root);
  printf("\n");

  // post-order traversal output: -5, 5, 20, 15, 10
  demolish(&root);
  printf("\n");

  return 0;
}
