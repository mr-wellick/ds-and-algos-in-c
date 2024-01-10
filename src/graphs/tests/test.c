#include "../../../unity/unity.h"
#include "../../linked-lists/linked-lists.h"
#include "../graphs.h"
#include <stdio.h>
#include <stdlib.h>

#define SEMITONES 22
#define STRINGS 7

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_graph(void) {
  Node *adjList[STRINGS] = {NULL};

  //     >(1)<--->(4) ---->(5)
  //    /          |       /|
  // (0)     ------|------- |
  //    \   v      v        v
  //     >(2) --> (3) <----(6)
  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 2);
  addEdge(adjList, 1, 4);
  addEdge(adjList, 2, 3);
  addEdge(adjList, 4, 1);
  addEdge(adjList, 4, 3);
  addEdge(adjList, 4, 5);
  addEdge(adjList, 5, 2);
  addEdge(adjList, 5, 6);
  addEdge(adjList, 6, 3);

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
  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 2);
  addEdge(adjList, 1, 4);
  addEdge(adjList, 2, 3);
  addEdge(adjList, 4, 1);
  addEdge(adjList, 4, 3);
  addEdge(adjList, 4, 5);
  addEdge(adjList, 5, 2);
  addEdge(adjList, 5, 6);
  addEdge(adjList, 6, 3);

  depthFirstTraversal(adjList, 0);
  destroyGraph(adjList, STRINGS);

  for (int i = 0; i < STRINGS; i++) {
    TEST_ASSERT_NULL(adjList[i]);
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_graph);
  RUN_TEST(test_depth_first_traversal);
  UNITY_END();

  return 0;
}
