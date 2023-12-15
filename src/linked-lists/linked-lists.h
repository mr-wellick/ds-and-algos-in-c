#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
  struct Node *head;
  struct Node *tail;
} DoublyLinkedList;

Node *createNode(int value);

DoublyLinkedList *initList();

void insertNode(DoublyLinkedList **list, int value);


//Node deleteNode(Node **list, int value);

//void printList(Node **list);

// Node *searchList(Node *list, int value) ;

#endif
