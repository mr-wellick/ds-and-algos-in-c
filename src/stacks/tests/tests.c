#include "../../../unity/unity.h"
#include "../stacks.h"
#include <stdlib.h>

void setUp(void) {}

void tearDown(void) {}

void test_insert_to_empty_stack(void) {
  StackItem *dummyStack = createStackItem(0);
  TEST_ASSERT_NOT_NULL(dummyStack);

  push(&dummyStack, 10);
  TEST_ASSERT_EQUAL_INT(10, dummyStack->next->vertex);
}

void test_insert_multiple_values(void) {
  StackItem *dummyStack = createStackItem(0);

  push(&dummyStack, 8);
  push(&dummyStack, 10);
  push(&dummyStack, 12);
  push(&dummyStack, 13);
  push(&dummyStack, 15);

  StackItem *curr = dummyStack->next;
  while (curr) {
    printf("The value of current vertex is: %d. \n", curr->vertex);
    curr = curr->next;
  }
}

void test_pop(void) {
  StackItem *dummyStack = createStackItem(0);

  push(&dummyStack, 8);
  push(&dummyStack, 10);

  StackItem *topValue = pop(&dummyStack);
  TEST_ASSERT_EQUAL_INT(10, topValue->vertex);
  free(topValue);
  topValue = NULL;

  topValue = pop(&dummyStack);
  TEST_ASSERT_EQUAL_INT(8, topValue->vertex);
  free(topValue);
  topValue = NULL;

  topValue = pop(&dummyStack);
  TEST_ASSERT_NULL(topValue);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_insert_to_empty_stack);
  RUN_TEST(test_insert_multiple_values);
  UNITY_END();
  return 0;
}
