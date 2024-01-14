#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
} Node;

Node *createNode(int value);

void insertAtHead(Node **list, int value);

void insertAtRear(Node **list, int value);

void insert(Node **list, int value);

void printList(Node **list);

void deleteNode(Node **list, int value);

int getSize(Node *list);

void demolish(Node **list);

#endif
