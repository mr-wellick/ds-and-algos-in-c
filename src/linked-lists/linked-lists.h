#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *createNode(int value);

Node *insertNode(Node *list, int value);

void printList(Node *list);

Node *searchList(Node *list, int value) ;

Node *deleteNode(Node *list, int value);

#endif
