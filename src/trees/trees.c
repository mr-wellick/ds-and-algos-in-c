#include "trees.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int value) {
  Node *rootNode = malloc(sizeof(Node));
  if (!rootNode) {
    printf("Error: malloc failed in createNode()");
    exit(EXIT_FAILURE);
  }

  rootNode->value = value;
  rootNode->left = NULL;
  rootNode->right = NULL;

  return rootNode;
}

void insert(Node **root, int value) {
  // if tree is empty, create root node, done.
  if (!(*root)) {
    *root = createNode(value);
    return;
  }

  Node *curr = *root;
  for (;;) {
    // if value exists, we're done.
    if (value == curr->value) {
      return;
    }

    // go left
    if (value < curr->value) {
      if (curr->left) {
        curr = curr->left;
      } else { // create node and insert into tree
        curr->left = createNode(value);
        return;
      }
      // go right
    } else if (value > curr->value) {
      if (curr->right) {
        curr = curr->right;
      } else { // create node and insert into tree
        curr->right = createNode(value);
        return;
      }
    }
  }
}

void erase(Node **root, int value) {
  if (!(*root)) {
    return;
  }

  // 1. find V in tree
  //     - use two pointers: root and a parent pointer
  // 2. if node found, delete from tree making sure to preserve the ordering
  // 	- 3 cases
  Node *parent = NULL;
  Node *curr = *root;
  while (curr) {
    // Case 1: our target node is a leaf node
    if (!curr->left && !curr->right) {
      if (curr->value == value) {
        printf("found the value: %d", curr->value);
        // The root node
        if (!parent) {
        } else {
          // Not the root node:
        }
        return;
      }
    } else if (curr->left || curr->right) { // Case 2: Target node has one child
      // The root node
      if (!parent) {
      } else {
        // Not the root node
      }
    } else if (curr->left &&
               curr->right) { // Case 3: Target node has two children
      // Replace its value with one from another node
      //   - 1. K's left subtree's largest-valued child
      //   - 2. K's right subtree's smallest-valued child
      //
      // These two replacements are the only suitable replacements for our
      // target node. Note, that both of them are either a leaf or have just one
      // child! So we pick one, copy its value up, then delete that node.
    }

    // note: need to advance pointer to reach above case
    parent = curr;
    if (value < curr->value) {
      curr = curr->left;
    }
    if (value > curr->value) {
      curr = curr->right;
    }
  }
}

bool find(Node **root, int value) {
  if (!(*root)) {
    return false;
  } else if (value == (*root)->value) {
    return true;
  } else if (value < (*root)->value) {
    return find(&(*root)->left, value);
  } else {
    return find(&(*root)->right, value);
  }
}

int min(Node **root) {
  if (!(*root)) {
    return -1;
  }

  if (!(*root)->left) {
    return (*root)->value;
  }

  return min(&(*root)->left);
}

int max(Node **root) {
  if (!(*root)) {
    return -1;
  }

  if (!(*root)->right) {
    return (*root)->value;
  }

  return max(&(*root)->right);
}

void printTree(Node **root) {
  if (!(*root)) {
    return;
  }

  // pre-order traversal
  printf("pre-order traversal: %d\n", (*root)->value);
  printTree(&(*root)->left);
  printTree(&(*root)->right);
}

void demolish(Node **root) {
  if (!(*root)) {
    return;
  }

  demolish(&(*root)->left);
  demolish(&(*root)->right);
  // post-order traversal
  printf("post-order traversal: %d\n", (*root)->value);

  free(*root);
}
