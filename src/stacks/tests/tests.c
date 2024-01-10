#include "../../../unity/unity.h"
#include "../stacks.h"
#include <stdlib.h>

void setUp(void) {}

void tearDown(void) {}

void test_insert_to_empty_stack(void) {
  Node *dummyNode = createNode(0);
  TEST_ASSERT_NOT_NULL(dummyNode);

  push(&dummyNode, 10);
  TEST_ASSERT_EQUAL_INT(10, dummyNode->next->vertex);
}

void test_insert_multiple_values(void) {
  Node *dummyNode = createNode(0);

  push(&dummyNode, 8);
  push(&dummyNode, 10);
  push(&dummyNode, 12);
  push(&dummyNode, 13);
  push(&dummyNode, 15);

  Node *curr = dummyNode->next;
  while (curr) {
    printf("The value of current vertex is: %d. \n", curr->vertex);
    curr = curr->next;
  }
}

void test_pop(void) {
  Node *dummyNode = createNode(0);

  push(&dummyNode, 8);
  push(&dummyNode, 10);

  Node *topValue = pop(&dummyNode);
  TEST_ASSERT_EQUAL_INT(10, topValue->vertex);
  free(topValue);
  topValue = NULL;

  topValue = pop(&dummyNode);
  TEST_ASSERT_EQUAL_INT(8, topValue->vertex);
  free(topValue);
  topValue = NULL;

  topValue = pop(&dummyNode);
  TEST_ASSERT_NULL(topValue);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_insert_to_empty_stack);
  RUN_TEST(test_insert_multiple_values);
  UNITY_END();
  return 0;
}
