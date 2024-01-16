#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>

StackHead *createStack(void) {
  StackHead *head = malloc(sizeof(StackHead));

  if (!head) {
    printf("Error allocating head in createStack()");
    exit(EXIT_FAILURE);
  }

  head->count = 0;
  head->next = NULL;

  return head;
}

StackItem *createStackItem(int vertex) {
  StackItem *stack = malloc(sizeof(StackItem));

  if (!stack) {
    printf("Error allocating new node in createStack()");
    exit(EXIT_FAILURE);
  }

  stack->vertex = vertex;
  stack->next = NULL;
  return stack;
}

void push(StackHead **head, int vertex) {
  if (!(*head)) {
    printf("please provide a dummy node");
    exit(EXIT_FAILURE);
  }

  if (!(*head)->next) {
    (*head)->next = createStackItem(vertex);
  } else {
    StackItem *new = createStackItem(vertex);

    new->next = (*head)->next;
    (*head)->next = new;
  }

  (*head)->count += 1;
}

int pop(StackHead **head) {
  if (!(*head) || !(*head)->next) {
    // value not found
    return -9999;
  }

  StackItem *top = (*head)->next;
  (*head)->next = top->next;
  (*head)->count -= 1;

  int copyOfValue = top->vertex;
  free(top);

  return copyOfValue;
}

void freeStack(StackHead **head) {
  if (!(*head)) {
    return;
  }

  StackItem *curr = (*head)->next;
  while (curr) {
    StackItem *next = curr->next;
    free(curr);
    curr = next;
  }

  free(*head);
  *head = NULL;
}
