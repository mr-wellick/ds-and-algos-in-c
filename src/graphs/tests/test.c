#include "../../../unity/unity.h"
#include "../graphs.h"
#include <stdlib.h>

#define SEMITONES 22
#define SIZE ((int)(sizeof(E2_adjacencyList) / sizeof(E2_adjacencyList[0])))

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_edge(void) {
  Edge *edge = createEdge(8);

  TEST_ASSERT_NOT_NULL(edge);
  TEST_ASSERT_EQUAL_INT(8, edge->to);

  free(edge);
  edge = NULL;

  TEST_ASSERT_NULL(edge);
}

void test_create_graph(void) {
  Edge E2_adjacencyList[SEMITONES] = {
      [8] = {10},  [10] = {12}, [12] = {13}, [13] = {15},
      [15] = {17}, [17] = {19}, [19] = {20}};
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_edge);
  RUN_TEST(test_create_graph);
  UNITY_END();

  return 0;
}
