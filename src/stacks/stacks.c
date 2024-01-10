#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>

StackItem *createStackItem(int vertex) {
  StackItem *newStackItem = malloc(sizeof(StackItem));

  if (!newStackItem) {
    printf("Error allocating new node in createStackItem()");
    exit(EXIT_FAILURE);
  }

  newStackItem->vertex = vertex;
  newStackItem->count = 0;
  newStackItem->next = NULL;
  return newStackItem;
}

void push(StackItem **stack, int vertex) {
  if (!(*stack)) {
    printf("please provide a dummy node");
    exit(EXIT_FAILURE);
    return;
  }

  if (!(*stack)->next) {
    (*stack)->next = createStackItem(vertex);
  } else {
    StackItem *newStackItem = createStackItem(vertex);
    newStackItem->next = (*stack)->next;
    (*stack)->next = newStackItem;
  }

  (*stack)->count += 1;
}

StackItem *pop(StackItem **stack) {
  if (!(*stack) || !(*stack)->next) {
    return NULL;
  }

  StackItem *top = (*stack)->next;
  (*stack)->next = top->next;

  (*stack)->count -= 1;

  return top;
}
