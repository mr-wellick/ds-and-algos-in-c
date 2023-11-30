#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value) {
  Node *rootNode = (Node *)malloc(
      sizeof(Node)); // type cast pointer return by malloc (void*) to Node*
  rootNode->value = value;
  rootNode->left = NULL;
  rootNode->right = NULL;

  return rootNode;
}

void insert(Node *curr, int value) {
  // if tree is empty, create root node, done.
  if (curr == NULL) {
    curr = createNode(value);
    return;
  }

  for (;;) {
    // if value exists, we're done.
    if (value == curr->value) {
      return;
    }

    // go left
    if (value < curr->value) {
      if (curr->left != NULL) {
        curr = curr->left;
      } else { // create node and insert into tree
        curr->left = createNode(value);
        return;
      }
      // go right
    } else if (value > curr->value) {
      if (curr->right != NULL) {
        curr = curr->right;
      } else { // create node and insert into tree
        curr->right = createNode(value);
        return;
      }
    }
  }
}

/* Big Oh of BST Search
 *
 * - In the average BST with N values, how many steps are required to find our
 * value? ==> Log2(N) steps.
 * - In the worst case BST with N values, how many steps are required to find
 * our value? ==> N steps.
 *
 * */
bool find(Node *curr, int value) {
  if (curr == NULL) {
    return false;
  } else if (value == curr->value) {
    return true;
  } else if (value < curr->value) {
    return find(curr->left, value);
  } else {
    return find(curr->right, value);
  }
}

/* Big Oh of printing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
void printTree(Node *curr) {
  if (curr == NULL) {
    return;
  }

  // pre-order traversal
  printf("pre-order traversal: %d\n", curr->value);
  printTree(curr->left);
  printTree(curr->right);
}

/* Big Oh of freeing BST
 *
 * - Since we need to visit each node, it's N steps.
 *
 * */
void demolish(Node *curr) {
  if (curr == NULL) {
    return;
  }

  demolish(curr->left);
  demolish(curr->right);
  // post-order traversal
  printf("post-order traversal: %d\n", curr->value);
  free(curr);
}

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

  // perform operations before freeing up the tree lol
  printTree(root);
  printf("\n");
  demolish(root);
  printf("\n");

  return 0;
}
