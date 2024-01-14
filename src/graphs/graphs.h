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
void depthFirstTraversal(Node *adjList[], int adjListSize, int currVertex);

/*
 * Process all of the vertices that are one dege away from the start vertex.
 * Then process all vertices that are two edges away.
 * Then process all vertices that are three edges away.
 * Etc...
 **/
void breadthFirstTraversal(Node *adjList[], int adjListSize, int currVertex);

#endif
