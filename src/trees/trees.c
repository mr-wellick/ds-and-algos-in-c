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
  // 1. find value in tree.
  // - Use two pointers: root and a parent pointer
  Node *parent = NULL;
  Node *curr = *root;

  while (curr && value != curr->value) {
    parent = curr;
    if (value < curr->value) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }

  // not found
  if (!curr)
    return;

  // Case 1: Target node has two children
  if (curr->left && curr->right) {
    // Replace its value with one from another node
    //   - 1. K's left subtree's largest-valued child  OR
    //   - 2. K's right subtree's smallest-valued child
    Node *replacement = max(curr->left);

    if (!replacement) {
      printf("can't find a suitable replacement for value to erase: %d\n",
             value);
      return;
    }

    int copyOfValue = replacement->value;
    erase(&curr, replacement->value);
    curr->value = copyOfValue;

    return;
  }
  // Case 2: our target node is a leaf node
  else if (!curr->left && !curr->right) {
    /* Subcase 1: our target node is NOT the root node */
    if (parent) {
      if (curr == parent->left) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else { /* Subcase 2: our target node is the root node */
      *root = NULL;
    }

    free(curr);
    return;
  }
  // Case 3: Target node has one child
  else {
    /* Subcase 1: our target node is NOT the root node */
    Node *child = curr->left ? curr->left : curr->right;

    if (parent) {
      if (curr == parent->left) {
        parent->left = child;
      } else {
        parent->right = child;
      }
    } else {
      /* Subcase 2: our target node is the root node */
      *root = child;
    }

    free(curr);
    return;
  }
}

Node *find(Node *root, int value) {
  if (!root) {
    return root;
  } else if (value == root->value) {
    return root;
  } else if (value < root->value) {
    return find(root->left, value);
  } else {
    return find(root->right, value);
  }
}

Node *min(Node *root) {
  if (!root) {
    return root;
  }

  if (!root->left) {
    return root;
  }

  return min(root->left);
}

Node *max(Node *root) {
  if (!root) {
    return root;
  }

  if (!root->right) {
    return root;
  }

  return max(root->right);
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
