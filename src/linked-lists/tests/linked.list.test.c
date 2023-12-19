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

// todo
void doubly_linked_list() {
  Node *dummy_head = createNode(0);

  // insert a single node into list
  insertNode(&dummy_head, 5);
  insertNode(&dummy_head, 14);
  insertNode(&dummy_head, 23);
  insertNode(&dummy_head, 100);

  printf("The address of head: %p\n", dummy_head->next);
  printf("The address of tail: %p\n\n", dummy_head->prev);

  Node *p = dummy_head->next;
  while (p) {
    printf("The address of current: %p\n", p);
    printf("The value is: %d \n", p->value);
    printf("The address of next: %p \n", p->next);
    printf("The address of prev: %p \n\n", p->prev);
    p = p->next;
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(doubly_linked_list);
  UNITY_END();

  return 0;
}
