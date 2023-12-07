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

// void insert(Node *curr, int value) {
//   // if tree is empty, create root node, done.
//   if (curr == NULL) {
//     curr = createNode(value);
//     return;
//   }
//
//   for (;;) {
//     // if value exists, we're done.
//     if (value == curr->value) {
//       return;
//     }
//
//     // go left
//     if (value < curr->value) {
//       if (curr->left != NULL) {
//         curr = curr->left;
//       } else { // create node and insert into tree
//         curr->left = createNode(value);
//         return;
//       }
//       // go right
//     } else if (value > curr->value) {
//       if (curr->right != NULL) {
//         curr = curr->right;
//       } else { // create node and insert into tree
//         curr->right = createNode(value);
//         return;
//       }
//     }
//   }
// }
//
// void erase(Node *curr, int value) {
//   // 1. find V in tree
//   //     - use two pointers: curr and a parent pointer
//   // 2. if node found, delete from tree making sure to preserve the ordering
//   // 	- 3 cases
//   Node *parent = NULL;
//   while (curr != NULL) {
//     if (value == curr->value) {
//       /* once we've found our target node, we have to delete it.
//        *
//        * - Case 1: our target node is a leaf (it has two sub-cases), which is
//        a node with 0 children!
//        * - Sub-case #1: The target node is NOT the root node
//        * 	- Unlink parent node from the target node (curr) by setting the
//        parent's appropriate link to NULL.
//        *        - Delete the target (curr) node.
//        * - Sub-case #2: The target node is the root node
//        *        - Set the root pointer to NULL
//        *        - Then delete the target (curr) node
//        */
//       if (!parent) {
//       // BUG: Issue with pointer. Review how pointers/refs are passed to
//       functions and diagram this code out to understand what's really
//       happening
//         free(curr);
//         curr = NULL;
//         return;
//       } else {
//         if (parent->right == curr) {
//           parent->right = NULL;
//         } else if(parent->left == curr){
//           parent->left = NULL;
//         }
//	free(curr);
//	return;
//       }
//       // - Case 2: our target node has one child (it has two sub-cases)
//       // 		- Sub case #1: The target node is NOT the root node
//       // 			- Relink the parent node to the target (curr)
//       // node's only child.
//       // 			- Then delete the target (curr) node.
//       // 		- Sub Case #2: The target node is the root node
//       // 			- Relink the root pointer to the target (curr)
//       // node's only child.
//       // 			- Then delete the target (curr) node.
//       //
//       // - Case 3: our target node has two children (we have to be careful
//       when
//       // deleting a node with two children)
//       // 		- note: we don't actually delete the node itself.
//       // Instead, we replace its value with one from another node!
//       // 		-       we want to replace the target node with either:
//       // 		- 1. K's left subtree's largest-valued child
//       // 		- 2. K's right subtree's smallest-valued child
//       //
//       //		- These two replacements are the only suitable
//       //replacements for our target node. Note, that both of them are either
//       a
//       //leaf or have just one child!
//       // 		- So we pick one, copy its value up, then delete that
//       // node.
//       //
//     }
//     if (value < curr->value) {
//       parent = curr;
//       curr = curr->left;
//     } else if (value > curr->value) {
//       parent = curr;
//       curr = curr->right;
//     }
//   }
// }
//
// bool find(Node *curr, int value) {
//   if (curr == NULL) {
//     return false;
//   } else if (value == curr->value) {
//     return true;
//   } else if (value < curr->value) {
//     return find(curr->left, value);
//   } else {
//     return find(curr->right, value);
//   }
// }
//
// int min(Node *curr) {
//   if (curr == NULL) {
//     return -1;
//   }
//
//   if (curr->left == NULL) {
//     return curr->value;
//   }
//
//   return min(curr->left);
// }
//
// int max(Node *curr) {
//   if (curr == NULL) {
//     return -1;
//   }
//
//   if (curr->right == NULL) {
//     return curr->value;
//   }
//
//   return max(curr->right);
// }
//
// void printTree(Node *curr) {
//   if (curr == NULL) {
//     return;
//   }
//
//   // pre-order traversal
//   printf("pre-order traversal: %d\n", curr->value);
//   printTree(curr->left);
//   printTree(curr->right);
// }

void demolish(Node *curr) {
  if (!curr) {
    return;
  }

  demolish(curr->left);
  demolish(curr->right);
  // post-order traversal
  printf("post-order traversal: %d\n", curr->value);

  free(curr);
  curr = NULL;
}
