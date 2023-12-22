#include "../../../unity/unity.h"
#include "../trees.h"
#include <stdlib.h>

// Optional: Any setup code that needs to run before each test
void setUp(void) {}

// Optional: Any teardown code that needs to run after each test
void tearDown(void) {}

void test_create_node(void) {
  Node *root = createNode(5);

  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_NULL(root->left);
  TEST_ASSERT_NULL(root->right);

  free(root);

  root = NULL;
  TEST_ASSERT_NULL(root);
}

void test_insertion() {
  Node *root = NULL;

  insert(&root, 5);
  insert(&root, 1);
  insert(&root, 20);
  insert(&root, 15);
  insert(&root, -4);

  printTree(&root);

  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_NOT_NULL(root->left);
  TEST_ASSERT_NOT_NULL(root->right);

  TEST_ASSERT_EQUAL_INT(1, root->left->value);
  TEST_ASSERT_NOT_NULL(root->left->left);
  TEST_ASSERT_NULL(root->left->right);

  TEST_ASSERT_EQUAL_INT(20, root->right->value);
  TEST_ASSERT_NOT_NULL(root->right->left);
  TEST_ASSERT_NULL(root->right->right);

  demolish(&root);

  root = NULL;
  TEST_ASSERT_NULL(root);
}

// void print_tree() {
//   Node *root = createNode(2);
//
//   insert(&root, 3);
//   insert(&root, -2);
//   insert(&root, 6);
//   //insert(&root, 2);
//   insert(&root, 25);
//
//   printTree(&root);
//   //demolish(&root);
//
//   //root = NULL;
//   //TEST_ASSERT_NULL(root);
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(test_insertion);
  // RUN_TEST(print_tree);
  UNITY_END();

  return 0;
}
