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
      demolish(&adjList[i]); // free doubly-linked list with help of dummy node:
                             // adjList[i]
      free(adjList[i]);      // free dummy node for doubly-linked list
      adjList[i] = NULL;
    }
  }
}

void depthFirstTraversal(Node *adjList[], int currVertex) {
  StackItem *dummyStack = createStackItem(-1);
  // push currVertex on the dummyStack
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
