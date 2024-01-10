#include "stacks.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int vertex) {
  Node *newNode = malloc(sizeof(Node));

  if (!newNode) {
    printf("Error allocating new node in createNode()");
    exit(EXIT_FAILURE);
  }

  newNode->vertex = vertex;
  newNode->count = 0;
  newNode->next = NULL;
  return newNode;
}

void push(Node **stack, int vertex) {
  if (!(*stack)) {
    printf("please provide a dummy node");
    exit(EXIT_FAILURE);
    return;
  }

  if (!(*stack)->next) {
    (*stack)->next = createNode(vertex);
  } else {
    Node *newNode = createNode(vertex);
    newNode->next = (*stack)->next;
    (*stack)->next = newNode;
  }

  (*stack)->count += 1;
}

Node *pop(Node **stack) {
  if (!(*stack) || !(*stack)->next) {
    return NULL;
  }

  Node *top = (*stack)->next;
  (*stack)->next = top->next;

  (*stack)->count -= 1;

  return top;
}
