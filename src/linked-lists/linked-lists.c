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

  return node;
}

// does node modify the list pointer
Node *insertNode(Node *list, int value) {
  Node *new_node = createNode(value);
  new_node->next = list;

  return new_node;
}

// since list is a copy of the original list pointer, there is no harm in
// changing it within the function
void printList(Node *list) {
  if (!list) {
    printf("nothining to print\n");
    return;
  }

  while (list) {
    printf("The value is: %d\n", list->value);
    list = list->next;
  }
}

Node *searchList(Node *list, int value) {
  while (list && list->value != value) {
    list = list->next;
  }

  return list;
}

Node *deleteNode(Node *list, int value) {
  Node *curr = list;
  Node *parent = NULL;

  for (; curr && curr->value != value; parent = curr, curr = curr->next)
    ;

  if (!curr) {
    return list;
  }
  if (!parent) {
    list = list->next;
  } else {
    parent->next = curr->next;
  }

  free(curr);

  return list;
}
