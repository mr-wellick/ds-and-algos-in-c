#include "graphs.h"
#include "../linked-lists/linked-lists.h"
#include "../queues/queue.h"
#include "../stacks/stacks.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void addEdge(Node *adjList[], int from, int to, int weight) {
  if (!adjList[from]) {
    Node *dummyHead = createNode(0, weight);
    insertAtRear(&dummyHead, to, weight);
    adjList[from] = dummyHead;
  } else if (adjList[from]) {
    insertAtRear(&adjList[from], to, weight);
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

bool findEdge(Node *adjList, int from, int to) {
  if (!adjList) {
    return false;
  }

  Node *p = adjList->next;
  while (p) {
    if (p->value == to) {
      return true;
    }
    p = p->next;
  }

  return false;
}

int minDistance(int dist[], bool done[], int adjListSize) {
  int min = INT_MAX;
  int min_index = -1;

  for (int i = 0; i < adjListSize; i++) {
    if (!done[i] && dist[i] < min) {
      min = dist[i];
      min_index = i;
    }
  }

  return min_index;
}

int *dijkstras(Node **adjList, int adjListSize, int currVertex) {
  int *dist = calloc(adjListSize, sizeof(int));
  bool done[adjListSize];

  for (int i = 0; i < adjListSize; i++) {
    dist[i] = INT_MAX;
    done[i] = false;
  }

  dist[currVertex] = 0; // distance from currVertex is always 0

  for (int i = 0; i < adjListSize - 1; i++) {
    int u = minDistance(dist, done, adjListSize);
    done[u] = true;

    Node *currEdge = adjList[u] ? adjList[u]->next : NULL;
    while (currEdge) {
      int v = currEdge->value;

      if (!done[v] && dist[u] != INT_MAX &&
          dist[u] + currEdge->weight < dist[v]) {
        dist[v] = dist[u] + currEdge->weight;
      }

      currEdge = currEdge->next;
    }
  }

  return dist;
}
