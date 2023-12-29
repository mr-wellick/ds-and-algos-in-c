#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge {
  int to;
} Edge;

Edge *createEdge(int to);

#endif
