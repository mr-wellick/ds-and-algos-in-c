#include "graphs.h"
#include "../linked-lists/linked-lists.h"
#include "../stacks/stacks.h"
#include <stdbool.h>
#include <stdio.h>

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

void depthFirstTraversal(Node *adjList[], int currVertex) {
  StackItem *dummyStack = createStackItem(-1);
  push(&dummyStack, currVertex);
  bool seen[7] = {false};

  while (dummyStack->count > 0) {
    // pop top item off the dummyStack and put it in variable c
    StackItem *c = pop(&dummyStack);
    printf("curr value %d\n", c->vertex);

    // if c has not been seen, drop a breadcrumb
    if (!seen[c->vertex]) {
      seen[c->vertex] = true;

      Node *list = adjList[c->vertex] ? adjList[c->vertex]->next : NULL;

      while (list) {
        if (!seen[list->value]) {
          push(&dummyStack, list->value);
        }
        list = list->next;
      }
    }

    free(c);
  }

  free(dummyStack);
}

void breadthFirstTraversal(Node *adjList[], int currVertex) {
    // Add starting vertex to our queue
    // Mark the starting vertex as "discovered"
    //
    // While the queue is not empty
    //  Dequeue the top vertex from the queue and place in c
    //  Process vertex c
    //
    //  For each vertex v directly reachable from c
    //      If v has not yet been "discovered"
    //          Mark v as "discovered"
    //          Insert vertex v into the queue
}
