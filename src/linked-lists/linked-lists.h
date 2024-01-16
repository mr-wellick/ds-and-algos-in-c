#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct Node {
  int value;
  int weight;
  struct Node *next;
  struct Node *prev;
} Node;

Node *createNode(int value, int weight);

void insertAtHead(Node **list, int value, int weight);

void insertAtRear(Node **list, int value, int weight);

void insert(Node **list, int value, int weig);

void printList(Node **list);

void deleteNode(Node **list, int value);

int getSize(Node *list);

void demolish(Node **list);

#endif
