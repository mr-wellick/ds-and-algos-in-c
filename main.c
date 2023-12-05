#include "trees.h"
#include <stdio.h>

int main(void) {
  // create BST and add values
  Node *root = createNode(10);
  /*      10
        /    \
       5      15
      / \     / \
    -5  N    N   N
    /\
   N N                */
  insert(root, 5);
  insert(root, 5);
  insert(root, 15);
  insert(root, -5);

  // find a value
  int needle = -5;
  printf("\n");
  printf("Was %d found?\n", needle);
  printf("True: 1 or False: 0\n");
  printf("Result: %d\n", find(root, needle));
  printf("\n");


  printTree(root);
  printf("\n");

  // find min in tree (-5)
  printf("The min value is: %d\n", min(root));
  // find max in tree (15)
  printf("The max value is: %d\n", max(root));
  printf("\n");

  // delete node
  erase(root, 15);

  // perform operations before freeing up the tree lol
  demolish(root);
  printf("\n");

  // create new tree
  Node *rootTwo = createNode(10);
  printTree(root);
  printf("\n");
  erase(rootTwo, 10);

  demolish(rootTwo);

  return 0;
}
