#ifndef TREE_H
#define TREE_H

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value);

void insert(Node *curr, int value);

/* Big Oh of BST Search
 *
 * - In the average BST with N values, how many steps are required to find our
 * value? ==> Log2(N) steps.
 * - In the worst case BST with N values, how many steps are required to find
 * our value? ==> N steps.
 *
 * */
bool find(Node *curr, int value);

/* Big Oh of printing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
void printTree(Node *curr);

/* Big Oh of freeing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
void demolish(Node *curr);

#endif
