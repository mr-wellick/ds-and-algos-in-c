#include "../../../unity/unity.h"
#include "../linked-lists.h"

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_node(void) {
  Node *list = createNode(5);

  TEST_ASSERT_EQUAL_INT(5, list->value);
  TEST_ASSERT_NULL(list->next);
  TEST_ASSERT_NULL(list->prev);
}

void test_create_list(void) {
  Node *list = NULL;
  insertNode(&list, 10);
  insertNode(&list, 15);

  TEST_ASSERT_EQUAL_INT(15, list->value);
  TEST_ASSERT_NOT_NULL(list->next);
  TEST_ASSERT_NULL(list->prev);

  TEST_ASSERT_EQUAL_INT(10, list->next->value);
  TEST_ASSERT_NULL(list->next->next);
  TEST_ASSERT_NOT_NULL(list->next->prev);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(test_create_list);
  UNITY_END();

  return 0;
}
