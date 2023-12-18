#include "linked-lists.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int value) {
  Node *node = malloc(sizeof(Node));

  if (!node) {
    printf("Error: malloc failed in createNode()");
    exit(EXIT_FAILURE);
  }
  node->value = value;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

DoublyLinkedList *initList() {
  DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

  if (!list) {
    printf("Error: malloc failed in initList()");
    exit(EXIT_FAILURE);
  }

  list->head = NULL;
  list->tail = NULL;

  return list;
}

// inserts to the begining of a linked list only
void insertNode(DoublyLinkedList **list, int value) {
  Node *new_node = createNode(value);

  // is there a case where this is not true?
  // how to simplify logic ?
  // review notes
  if ((*list)->head && (*list)->tail) {
    new_node->next = (*list)->head;
    (*list)->head->prev = new_node;
    (*list)->head = new_node;
  } else {
    (*list)->head = new_node;
    (*list)->tail = new_node;
  }
}

// void printList(Node **list) {
//   if (!*list) {
//     printf("nothining to print\n");
//     return;
//   }
//
//   while (*list) {
//     printf("The value is: %d\n", (*list)->value);
//     printf("The node->next %p\n", (*list)->next);
//     printf("The node->prev %p\n", (*list)->prev);
//     *list = (*list)->next;
//   }
// }

// Node *searchList(Node *list, int value) {
//   while (list && list->value != value) {
//     list = list->next;
//   }
//
//   return list;
// }

// Node deleteNode(Node **list, int value) {
//   Node *curr = list;
//   Node *parent = NULL;
//
//   for (; curr && curr->value != value; parent = curr, curr = curr->next)
//     ;
//
//   if (!curr) {
//     return;
//   }
//   if (!parent) {
//     list = list->next;
//   } else {
//     parent->next = curr->next;
//   }
//
//   free(curr);
// }
