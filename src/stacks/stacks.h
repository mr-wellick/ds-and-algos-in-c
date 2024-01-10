#ifndef STACKS_H
#define STACKS_H

typedef struct StackItem {
  int vertex;
  int count;
  struct StackItem *next;
} StackItem;

StackItem *createStackItem(int vertex);

void push(StackItem **stack, int vertex);

StackItem *pop(StackItem **stack);

#endif
