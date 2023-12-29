#include "graphs.h"
#include <stdio.h>
#include <stdlib.h>

Edge *createEdge(int to) {
  Edge *edge = malloc(sizeof(Edge));

  if (!edge) {
    printf("Error: malloc failed in createEdge()");
    exit(EXIT_FAILURE);
  }

  edge->to = to;

  return edge;
}
