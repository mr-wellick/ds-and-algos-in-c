#include "../../../unity/unity.h"
#include "../stacks.h"

void setUp(void) {}

void tearDown(void) {}

void test_insert_to_empty_stack(void) {
  Node *dummyNode = createNode(0);
  TEST_ASSERT_NOT_NULL(dummyNode);

  insert(&dummyNode, 10);
  TEST_ASSERT_EQUAL_INT(10, dummyNode->next->vertex);
}

void test_insert_multiple_values(void) {
  Node *dummyNode = createNode(0);

  insert(&dummyNode, 8);
  insert(&dummyNode, 10);
  insert(&dummyNode, 12);
  insert(&dummyNode, 13);
  insert(&dummyNode, 15);

  Node *curr = dummyNode->next;
  while (curr) {
    printf("The value of current vertex is: %d. \n", curr->vertex);
    curr = curr->next;
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_insert_to_empty_stack);
  RUN_TEST(test_insert_multiple_values);
  UNITY_END();
  return 0;
}
