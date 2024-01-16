#ifndef STACKS_H
#define STACKS_H

typedef struct StackItem {
  int vertex;
  struct StackItem *next;
} StackItem;

typedef struct StackHead {
  int count;
  struct StackItem *next;
} StackHead;

StackHead *createStack(void);

StackItem *createStackItem(int vertex);

void push(StackHead **stack, int vertex);

int pop(StackHead **stack);

void freeStack(StackHead **head);

#endif
