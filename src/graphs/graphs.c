#include "graphs.h"
#include "../linked-lists/linked-lists.h"
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

void depthFirstTraversal(Node *adjList[]) {

}
