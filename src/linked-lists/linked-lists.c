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

// inserts to the begining of a linked list only
void insertNode(Node **list, int value) {
  Node *new_node = createNode(value);
  new_node->next = *list;
  new_node->prev = NULL;

  if (*list) {
    (*list)->prev = new_node;
  }

  *list = new_node;
}

//void printList(Node **list) {
//  if (!*list) {
//    printf("nothining to print\n");
//    return;
//  }
//
//  while (*list) {
//    printf("The value is: %d\n", (*list)->value);
//    printf("The node->next %p\n", (*list)->next);
//    printf("The node->prev %p\n", (*list)->prev);
//    *list = (*list)->next;
//  }
//}

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
