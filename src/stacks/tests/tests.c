#include "../../../unity/unity.h"
#include "../stacks.h"

void setUp(void) {}

void tearDown(void) {}

void test_insert_to_empty_stack(void) {
    Node *stack = NULL;
    TEST_ASSERT_NULL(stack);

    insert(&stack, 10);
    TEST_ASSERT_EQUAL_INT(10, stack->vertex);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_insert_to_empty_stack);
  UNITY_END();
  return 0;
}
