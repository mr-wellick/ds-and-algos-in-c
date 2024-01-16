#include "../../../unity/unity.h"
#include "../../linked-lists/linked-lists.h"
#include "../graphs.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STRINGS 7

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_graph(void) {
  Node *adjList[STRINGS] = {NULL};

  //     >(1)<--8-->(4) --1-->(5)
  //   2/           |    4--/ |
  //   /            5  /      2
  // (0)     ------|--------- |
  //   9\   v      v          v
  //     >(2)--7-> (3) <--0-(6)
  addEdge(adjList, 0, 1, 2);
  addEdge(adjList, 0, 2, 9);
  addEdge(adjList, 1, 4, 8);
  addEdge(adjList, 2, 3, 7);
  addEdge(adjList, 4, 1, 8);
  addEdge(adjList, 4, 3, 5);
  addEdge(adjList, 4, 5, 1);
  addEdge(adjList, 5, 2, 4);
  addEdge(adjList, 5, 6, 2);
  addEdge(adjList, 6, 3, 0);

  printGraph(adjList, STRINGS);
  destroyGraph(adjList, STRINGS);

  for (int i = 0; i < STRINGS; i++) {
    TEST_ASSERT_NULL(adjList[i]);
  }
}

void test_depth_first_traversal(void) {
  Node *adjList[STRINGS] = {NULL};

  //     >(1)<--->(4) ---->(5)
  //    /          |       /|
  // (0)     ------|------- |
  //    \   v      v        v
  //     >(2) --> (3) <----(6)
  addEdge(adjList, 0, 1, 2);
  addEdge(adjList, 0, 2, 9);
  addEdge(adjList, 1, 4, 8);
  addEdge(adjList, 2, 3, 7);
  addEdge(adjList, 4, 1, 8);
  addEdge(adjList, 4, 3, 5);
  addEdge(adjList, 4, 5, 1);
  addEdge(adjList, 5, 2, 4);
  addEdge(adjList, 5, 6, 2);
  addEdge(adjList, 6, 3, 0);

  /* Since we start at 0, the function should print: 0, 2, 3, 1, 4, 5, 6
   *
   *  - The first path we traverse through: 0, 2, 3.
   *  - We go back to 0 and traverse through the second path: 0, 1, 4, 5, 6
   *  - Any vertices previously visited will be ignore.
   */
  depthFirstTraversal(adjList, STRINGS, 0);
  destroyGraph(adjList, STRINGS);

  for (int i = 0; i < STRINGS; i++) {
    TEST_ASSERT_NULL(adjList[i]);
  }
}

void test_breadth_first_traversal(void) {
  Node *adjList[STRINGS] = {NULL};

  //     >(1)<--->(4) ---->(5)
  //    /          |       /|
  // (0)     ------|------- |
  //    \   v      v        v
  //     >(2) --> (3) <----(6)
  addEdge(adjList, 0, 1, 2);
  addEdge(adjList, 0, 2, 9);
  addEdge(adjList, 1, 4, 8);
  addEdge(adjList, 2, 3, 7);
  addEdge(adjList, 4, 1, 8);
  addEdge(adjList, 4, 3, 5);
  addEdge(adjList, 4, 5, 1);
  addEdge(adjList, 5, 2, 4);
  addEdge(adjList, 5, 6, 2);
  addEdge(adjList, 6, 3, 0);

  // outout: 0 -> 1, 2 -> 4, 3 -> 5 -> 6
  breadthFirstTraversal(adjList, STRINGS, 0);
  destroyGraph(adjList, STRINGS);
}

void test_dijkstras(void) {
  Node *adjList[STRINGS] = {NULL};

  //     >(1)<--->(4) ---->(5)
  //    /          |       /|
  // (0)     ------|------- |
  //    \   v      v        v
  //     >(2) --> (3) <----(6)
  addEdge(adjList, 0, 1, 2);
  addEdge(adjList, 0, 2, 9);
  addEdge(adjList, 1, 4, 8);
  addEdge(adjList, 2, 3, 7);
  addEdge(adjList, 4, 1, 8);
  addEdge(adjList, 4, 3, 5);
  addEdge(adjList, 4, 5, 1);
  addEdge(adjList, 5, 2, 4);
  addEdge(adjList, 5, 6, 2);
  addEdge(adjList, 6, 3, 0);

  int *dist = dijkstras(adjList, STRINGS, 0);
  for (int i = 0; i < STRINGS; i++) {
    printf("from 0 to %d: the weight is %d\n", i, dist[i]);
  }

  free(dist);
  destroyGraph(adjList, STRINGS);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_graph);
  RUN_TEST(test_depth_first_traversal);
  RUN_TEST(test_breadth_first_traversal);
  RUN_TEST(test_dijkstras);
  UNITY_END();

  return 0;
}
