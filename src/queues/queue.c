#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *createQueue(int size) {
  Queue *q = malloc(sizeof(Queue));

  if (!q) {
    printf("Error in createQueue()");
    exit(EXIT_FAILURE);
  }

  q->head = 0;
  q->tail = 0;
  q->count = 0;
  q->size = size;
  q->arr = calloc(size, sizeof(int));

  return q;
}

void insert(Queue **q, int value) {
  // insert value into queue
  if ((*q)->tail < (*q)->size) {
    (*q)->arr[(*q)->tail] = value;
    (*q)->tail += 1;
    (*q)->count += 1;
  }
}

