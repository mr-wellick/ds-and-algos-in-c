#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *createNode(int value);

Node *insert(Node *list, int value);

void printList(Node *list);

int searchList(Node *list, int value) ;

#endif
