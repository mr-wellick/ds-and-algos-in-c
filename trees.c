#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

void printTree(Node *curr) {
  if (curr == NULL) {
    return;
  }

  // pre-order traversal
  printf("pre-order traversal: %d\n", curr->value);
  printTree(curr->left);
  printTree(curr->right);
}

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

