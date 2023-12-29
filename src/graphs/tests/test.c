#include "../../../unity/unity.h"
#include "../graphs.h"
#include <stdlib.h>

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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_edge);
  UNITY_END();

  return 0;
}
