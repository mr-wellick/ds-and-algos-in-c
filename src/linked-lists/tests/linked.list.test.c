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

  free(list);
}

void test_insert_at_head(void) {
  Node *dummy_head = createNode(0);
  insertAtHead(&dummy_head, 5);

  TEST_ASSERT_EQUAL_INT(5, dummy_head->next->value);
  TEST_ASSERT_EQUAL_PTR(dummy_head->next, dummy_head->prev);

  demolish(&dummy_head);
}

void test_insert_at_rear(void) {
  Node *dummy_head = createNode(0);
  insertAtRear(&dummy_head, 5);

  TEST_ASSERT_EQUAL_INT(5, dummy_head->next->value);
  TEST_ASSERT_EQUAL_PTR(dummy_head->next, dummy_head->prev);

  insertAtRear(&dummy_head, 15);
  TEST_ASSERT_EQUAL_INT(15, dummy_head->prev->value);
  TEST_ASSERT_NOT_EQUAL(dummy_head->next, dummy_head->prev);

  demolish(&dummy_head);
}

void test_insertion_methods(void) {
  Node *dummy_head = createNode(0);
  insertAtHead(&dummy_head, 1);
  insertAtRear(&dummy_head, 2);
  insertAtHead(&dummy_head, 4);
  insertAtHead(&dummy_head, 5);
  insert(&dummy_head, 3);
  insert(&dummy_head, 50);

  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_insert(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 1);
  insert(&dummy_head, 4);
  insert(&dummy_head, 50);
  insert(&dummy_head, 2);
  insert(&dummy_head, 6);
  insert(&dummy_head, 3);
  insert(&dummy_head, 5);

  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_delete_single_node(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 1);

  // printList(&dummy_head);
  deleteNode(&dummy_head, 1);
  deleteNode(&dummy_head, 1);
  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_delete_middle_node(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 5);
  insert(&dummy_head, 40);
  insert(&dummy_head, 1);

  // printList(&dummy_head);
  deleteNode(&dummy_head, 5);
  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_delete_last_node(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 5);
  insert(&dummy_head, 40);
  insert(&dummy_head, 1);

  // printList(&dummy_head);
  deleteNode(&dummy_head, 40);
  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_delete_all_nodes(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 5);
  insert(&dummy_head, 40);
  insert(&dummy_head, 1);

  deleteNode(&dummy_head, 40);
  deleteNode(&dummy_head, 1);
  deleteNode(&dummy_head, 5);

  // printList(&dummy_head);
  demolish(&dummy_head);
}

void test_insert_duplicate_node(void) {
  Node *dummy_head = createNode(0);

  insert(&dummy_head, 5);
  insert(&dummy_head, 5);
  demolish(&dummy_head);

  // printList(&dummy_head);
}

void test_demolish_list(void) {
  Node *dummy_head = createNode(0);

  demolish(&dummy_head);

  insert(&dummy_head, 1);
  insert(&dummy_head, 4);
  insert(&dummy_head, 50);
  insert(&dummy_head, 2);
  insert(&dummy_head, 6);
  insert(&dummy_head, 3);
  insert(&dummy_head, 5);

  demolish(&dummy_head);

  printList(&dummy_head);
}

void test_get_size(void){
  Node *dummy_head = createNode(0);
  int size = 7;

  insert(&dummy_head, 1);
  insert(&dummy_head, 4);
  insert(&dummy_head, 50);
  insert(&dummy_head, 2);
  insert(&dummy_head, 6);
  insert(&dummy_head, 3);
  insert(&dummy_head, 5);

  TEST_ASSERT_EQUAL_INT(size, getSize(dummy_head));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(test_insert_at_head);
  RUN_TEST(test_insert_at_rear);
  RUN_TEST(test_insertion_methods);
  RUN_TEST(test_insert);
  RUN_TEST(test_delete_single_node);
  RUN_TEST(test_delete_middle_node);
  RUN_TEST(test_delete_last_node);
  RUN_TEST(test_delete_all_nodes);
  RUN_TEST(test_insert_duplicate_node);
  RUN_TEST(test_demolish_list);
  RUN_TEST(test_get_size);
  UNITY_END();

  return 0;
}
