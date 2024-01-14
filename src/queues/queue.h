#ifndef QUEUES_H
#define QUEUES_H

#include <stdlib.h>

typedef struct Queue {
  int head;
  int tail;
  int count;
  int size;
  int *arr;
} Queue;

Queue *createQueue(int size); 

void enqueue(Queue **q, int value);

int dequeue(Queue **q);

void detonate(Queue **q);

#endif
