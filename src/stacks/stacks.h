#ifndef STACKS_H
#define STACKS_H

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

Node *createNode(int vertex);

void insert(Node **stack, int vertex);

#endif
