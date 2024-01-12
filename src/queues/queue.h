#ifndef QUEUES_H
#define QUEUES_H

typedef struct Queue {
  int head;
  int tail;
  int count;
  int size;
  int *arr;
} Queue;

Queue *createQueue(int size); 

void insert(Queue **q, int value);

#endif
