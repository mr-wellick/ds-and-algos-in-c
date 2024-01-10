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

void depthFirstTraversal(int curVertex) {
  // depth_first_search_with_stack(start_room)
  //
  // push start_room on the stack
  //
  // while the stack in not empty
  //      pop the top item off the stack and put it in a variable c
  //
  //      if c hasn't been visited yet
  //          Drop a breadcrumb (we've visited the current room)
  //
  //          For each door d leaving the room
  //              if the room r behind door d hasn't been visited
  //                  Push r onto the stack
}
