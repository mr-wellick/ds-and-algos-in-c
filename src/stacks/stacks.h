#ifndef STACKS_H
#define STACKS_H

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

Node *createNode(int vertex);

void push(Node **stack, int vertex);

Node *pop(Node **stack);

#endif
