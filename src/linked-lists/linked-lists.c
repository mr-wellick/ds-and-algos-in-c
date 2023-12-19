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

void insertNode(Node **list, int value) {
  Node *new_node = createNode(value);

  if (!(*list)->next) {
    // if our list is empty -> add to front
    new_node->next = (*list)->next;
    (*list)->next = new_node;
    (*list)->prev = new_node;
  } else if ((*list)->next) {
    // if node belongs to top of list containing 1 or more nodes -> add to front
    new_node->next = (*list)->next;
    (*list)->next->prev = new_node;
    (*list)->next = new_node;
  } else {
    // if node belongs in the middle
    // 	-> use traversal loop to find the node just ABOVE where you want to
    // insert our new item
    // 	-> allocate and fill new node
    // 	-> link new node into the list right after the ABOVE node
  }

  // if add to end
  // 	-> use a temp var to traverse list to end
  // 	-> update last entry to point to new node
  // 	-> set new_node->next = NULL
}

// two cases
// 1. list is empty
// 2. existing list has one or more nodes
// void insertToEnd();

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
