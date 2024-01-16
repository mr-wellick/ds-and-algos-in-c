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

/*
 * Dijkstra's algo splits vertices into two distict sets: unsettled and settled
 *
 *  - Unsettled vertex: A vertex v is unsettled if we don't know the optimal distance to it from the starting vertex s.
 *  - Settled vertex: A vertex v is settled if we have learned the optimal distance to it from the starting vertex s.
 *
 * Initially, all vertices are unsettled. Ends once all vertices are in the settled set.
 *
 *  - Dijkstra's Algorithm uses 2 data structures
 *  
 *  1. An array called Dist that holds the current best known cost to get from s to every other vertex in the graph. 
 *
 *      for each vertex i, Dist[i] starts out with a value of
 *          0 for vertex s
 *          Infinity for all other vertices
 *
 *  2. An array called Done that holds true for each vertex that has been fully processed and false otherwise.
 *
 *      - for each vertex i, Done[i] starts out with a value of false
 *
 **/
void dijkstras(Node *adjList[], int adjListSize, int currVertex);

#endif
