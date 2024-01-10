#ifndef GRAPH_H
#define GRAPH_H

#include "../linked-lists/linked-lists.h"

void addEdge(Node *adjList[], int from, int to);

// modularize length later
void printGraph(Node *adjList[], int length);

// modularize length later
void destroyGraph(Node *adjList[], int length);

/*
 * A depth-first traversal keeps moving forward until it hits a dead end or a
 * previously-visited vertex. Then it backtracks and tries another path.
 **/
void depthFirstTraversal(Node *adjList[], int currVertex);

#endif
