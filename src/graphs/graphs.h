#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge {
  int to;
} Edge;

Edge *createEdge(int to);

/*
 * A depth-first traversal keeps moving forward until it hits a dead end or a
 * previously-visited vertex. Then it backtracks and tries another path.
 **/
void depthFirstTraversal(int curVertex);

#endif
