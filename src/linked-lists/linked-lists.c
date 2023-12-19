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

void insertAtHead(Node **list, int value) {
  Node *new_node = createNode(value);

  // if our list is empty -> add to front
  if (!(*list)->next) {
    new_node->next = (*list)->next;
    (*list)->next = new_node;
    (*list)->prev = new_node;
  } else {
    // if node belongs to top of list containing 1 or more nodes -> add to front
    new_node->next = (*list)->next;
    (*list)->next->prev = new_node;
    (*list)->next = new_node;
  }
}

void insertAtRear(Node **list, int value) {
  // if our list is empty -> add to front
  if (!(*list)->next) {
    insertAtHead(list, value);
  } else {
    // add node to rear
    Node *new_node = createNode(value);
    (*list)->prev->next = new_node;
    new_node->next = NULL;
    new_node->prev = (*list)->prev;
    (*list)->prev = new_node;
  }
}

void insert(Node **list, int value) {
  Node *new_node = createNode(value);

  // if our list is empty -> add to front
  if (!(*list)->next) {
    insertAtHead(list, value);
    return;
  }

  // if value is less than head  -> add to front
  if (value < (*list)->next->value) {
    insertAtHead(list, value);
  } else if (value > (*list)->prev->value) {
    // if value is greater than tail -> add to end
    insertAtRear(list, value);
  } else {
    // add somewhere in the middle
    Node *p = (*list)->next;
    while (p) {
      if (value < p->value)
        break;
      p = p->next;
    }

    new_node->next = p;
    new_node->prev = p->prev;
    p->prev->next = new_node;
    p->prev = new_node;
  }
}

void printList(Node **list) {

  if (!(*list)->next) {
    printf("nothing to print\n");
    return;
  }

  printf("The address of head: %p\n", (*list)->next);
  printf("The address of tail: %p\n\n", (*list)->prev);

  Node *p = (*list)->next;
  while (p) {
    printf("------------------------------------\n");
    printf("The address of current: %p\n", p);
    printf("The value is: %d \n", p->value);
    printf("The address of next: %p \n", p->next);
    printf("The address of prev: %p \n\n", p->prev);
    p = p->next;
  }
}

void deleteNode(Node **list, int value) {
  Node *curr = (*list)->next;
  Node *parent = NULL;

  for (; curr && curr->value != value; parent = curr, curr = curr->next)
    ;

  if (!curr) {
    return;
  }

  // beginning of list
  if (!parent) {
    // point to new head
    (*list)->next = curr->next;

    // more than 1 node
    if (curr->next) {
      curr->next->prev = NULL;
    } else {
      // only one node
      (*list)->prev = NULL;
    }
  } else {
    parent->next = curr->next;

    // somewhere in the middle
    if (curr->next) {
      curr->next->prev = parent;
    } else {
      // at the end of the list: update tail pointer
      (*list)->prev = parent;
    }
  }

  free(curr);
}
