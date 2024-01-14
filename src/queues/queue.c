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
  if ((*q)->count < (*q)->size) {
    (*q)->arr[(*q)->tail] = value;

    if ((*q)->tail == (*q)->size - 1) {
      (*q)->tail = 0;
    } else {
      (*q)->tail += 1;
    }

    (*q)->count += 1;
  }
}

int dequeue(Queue **q) {
  if ((*q)->count > 0) {
    int item = (*q)->arr[(*q)->head];
    if ((*q)->head == (*q)->size - 1) {
      (*q)->head = 0;
    } else {
      (*q)->head += 1;
    }

    (*q)->count -= 1;

    return item;
  }

  // not found:
  return -9999;
}
void detonate(Queue **q) {
  free((*q)->arr);
  free(*q);

  (*q) = NULL;
}
