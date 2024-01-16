#include "graphs.h"
#include "../linked-lists/linked-lists.h"
#include "../queues/queue.h"
#include "../stacks/stacks.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void addEdge(Node *adjList[], int from, int to) {
  if (!adjList[from]) {
    Node *dummyHead = createNode(0);
    insertAtRear(&dummyHead, to);
    adjList[from] = dummyHead;
  } else if (adjList[from]) {
    insertAtRear(&adjList[from], to);
  }
}

void printGraph(Node *adjList[], int length) {
  for (int i = 0; i < length; i++) {
    // adjList[i] points to the dummy node
    // adjList[i]->next points to the actual first node
    Node *curr = adjList[i] ? adjList[i]->next : NULL;

    while (curr) {
      printf("From %d to %d\n", i, curr->value);
      curr = curr->next;
    }
  }
}

void destroyGraph(Node *adjList[], int length) {
  for (int i = 0; i < length; i++) {
    if (adjList[i]) {
      // free doubly-linked list with help of dummy node: adjList[i]
      demolish(&adjList[i]);
      // free dummy node for doubly-linked list
      free(adjList[i]);
      adjList[i] = NULL;
    }
  }
}

void depthFirstTraversal(Node *adjList[], int adjListSize, int currVertex) {
  StackHead *dummyStack = createStack();
  push(&dummyStack, currVertex);

  bool *seen = calloc(adjListSize, sizeof(bool));

  while (dummyStack->count > 0) {
    int c = pop(&dummyStack);
    printf("curr value %d\n", c);

    if (!seen[c]) {
      seen[c] = true; // if c has not been seen, drop a breadcrumb

      Node *list = adjList[c] ? adjList[c]->next : NULL;
      while (list) {
        if (!seen[list->value]) {
          push(&dummyStack, list->value);
        }
        list = list->next;
      }
    }
  }

  freeStack(&dummyStack);
  free(seen);
}

void breadthFirstTraversal(Node *adjList[], int adjListSize, int currVertex) {
  // note: circular queue is nice but not knowing how many items we will need
  // in advance is a problem. it's possible that we allocate a smaller or larger
  // than needed array size for the queue.
  // will lead to seg fault errors
  Queue *q = createQueue(adjListSize);
  enqueue(&q, currVertex);

  bool *seen = calloc(adjListSize, sizeof(bool));
  seen[currVertex] = true; // Mark the starting vertex as "discovered"

  while (q->count > 0) {
    int c = dequeue(&q);
    printf("curr value %d\n", c);

    Node *list = adjList[c] ? adjList[c]->next : NULL;
    while (list) {
      if (!seen[list->value]) {
        seen[list->value] = true;
        enqueue(&q, list->value);
      }

      list = list->next;
    }
  }

  detonate(&q);
  free(seen);
}
