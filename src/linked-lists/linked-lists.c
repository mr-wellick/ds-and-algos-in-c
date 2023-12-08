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
Node *insert(Node *list, int value) {
  Node *new_node = createNode(value);
  new_node->next = list;

  return new_node;
}

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

int searchList(Node *list, int value) {
  while (list) {
    if (list->value == value) {
      return list->value;
    }
    list = list->next;
  }

  return -1;
}
