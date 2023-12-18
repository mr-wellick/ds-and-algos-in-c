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

void init_doubly_linked_list(void) {
  DoublyLinkedList *list = initList();

  TEST_ASSERT_NULL(list->head);
  TEST_ASSERT_NULL(list->tail);
}

// todo
void doubly_linked_list() {
  DoublyLinkedList *list = initList();
  insertNode(&list, 5);
  insertNode(&list, 2);
  insertNode(&list, 33);

  TEST_ASSERT_EQUAL_INT(33, list->head->value);
  TEST_ASSERT_NOT_NULL(list->head->next);
  TEST_ASSERT_NULL(list->head->prev);

  TEST_ASSERT_EQUAL_INT(5, list->tail->value);
  TEST_ASSERT_NULL(list->tail->next);
  TEST_ASSERT_NOT_NULL(list->tail->prev);

  while (list->head) {
    TEST_ASSERT_NOT_NULL(list->head);
    list->head = list->head->next;
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(init_doubly_linked_list);
  RUN_TEST(doubly_linked_list);
  UNITY_END();

  return 0;
}
