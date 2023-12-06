#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;


Node *createNode(int value);

/* Big Oh of BST Insertion
 *
 * - It's Log2(N) because first we have to use a binary search to find where to insert our node.
 *   Recall, binary search is Log2(N).
 *
 * */
//void insert(Node *curr, int value);

/* Big Oh of BST Deletion
 *
 * - Not so simple
 *
 * */
//void erase(Node *curr, int value);

/* Big Oh of BST Search
 *
 * - In the average BST with N values, how many steps are required to find our
 *   value? ==> Log2(N) steps.
 * - In the worst case BST with N values, how many steps are required to find
 *   our value? ==> N steps.
 *
 * */
//bool find(Node *curr, int value);

/* Big Oh of printing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
//void printTree(Node *curr);

/* Big Oh of freeing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
void demolish(Node *curr);

/* Big Oh of Finding the min value.
 *
 * - The min value is located to the left-most node.
 * - This depends on whether the tree is balanced or not.
 *
 * */
//int min(Node *curr);

/* Big Oh of finding the max value.
 *
 * - The max value is located to the right-most node.
 * - This depends on whether the tree is balanced or not.
 *
 * */
//int max(Node *curr);

#endif
