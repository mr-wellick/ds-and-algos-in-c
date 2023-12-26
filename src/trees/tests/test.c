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

void test_tree_insertion() {
  Node *root = NULL;

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  // since our printTree method employs pre-order traversal, expected output
  // should be: 2, -2, 25, 6, 3
  printTree(&root);
  printf("\n");

  // since our demolish method employs post-order traversal, expected output
  // should be: 2, -2, 25, 6, 3
  demolish(&root);

  root = NULL;
  TEST_ASSERT_NULL(root);
}

void test_find_value() {
  Node *root = NULL;

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  TEST_ASSERT_EQUAL_INT(25, find(&root, 25));
  TEST_ASSERT_EQUAL_INT(-1, find(&root, 100));

  demolish(&root);
  root = NULL;

  TEST_ASSERT_NULL(root);
}

void test_find_min() {
  Node *root = NULL;

  TEST_ASSERT_EQUAL_INT(-1, min(root));

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  TEST_ASSERT_EQUAL_INT(-2, min(root));

  demolish(&root);
  root = NULL;

  TEST_ASSERT_NULL(root);
}

void test_find_max() {
  Node *root = NULL;

  TEST_ASSERT_EQUAL_INT(-1, max(root));

  insert(&root, 3);
  insert(&root, -2);
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 25);

  TEST_ASSERT_EQUAL_INT(25, max(root));

  demolish(&root);
  root = NULL;

  TEST_ASSERT_NULL(root);
}

void test_erase_leaf_node() {
  // the root node
  Node *root = NULL;

  insert(&root, 5);
  erase(&root, 5);
  printTree(&root);

  TEST_ASSERT_NULL(root);

  // not the root node
  insert(&root, 5);
  insert(&root, 3);
  erase(&root, 3);

  TEST_ASSERT_NOT_NULL(root);
  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_NULL(root->left);
  TEST_ASSERT_NULL(root->right);

  demolish(&root);
  root = NULL;

  TEST_ASSERT_NULL(root);
}

void test_erase_node_w_one_child() {
  // the root node
  Node *root = NULL;

  insert(&root, 5);
  insert(&root, 3);
  erase(&root, 5);

  // pre-order: 3
  printTree(&root);

  TEST_ASSERT_NOT_NULL(root);
  TEST_ASSERT_EQUAL_INT(3, root->value);

  // post-order: 3
  demolish(&root);
  root = NULL;
  TEST_ASSERT_NULL(root);

  // not the root node
  insert(&root, 5);
  insert(&root, 3);
  insert(&root, 1);
  erase(&root, 3);

  // pre-order: 5, 1
  printTree(&root);

  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_EQUAL_INT(1, root->left->value);
  TEST_ASSERT_NULL(root->right);

  // post-order: 1, 5
  demolish(&root);
  root = NULL;
  TEST_ASSERT_NULL(root);
}

void test_erase_node_w_two_child() {
  // the root node
  Node *root = NULL;
  insert(&root, 5);
  insert(&root, 2);
  insert(&root, 7);

  erase(&root, 5);
  TEST_ASSERT_EQUAL_INT(7, root->value);
  TEST_ASSERT_EQUAL_INT(2, root->left->value);
  TEST_ASSERT_NULL(root->right);

  // post-order: 2, 7
  demolish(&root);
  root = NULL;

  // not the root node
  insert(&root, 5);
  insert(&root, 3);
  insert(&root, -1);
  insert(&root, 4);

  erase(&root, 3);
  TEST_ASSERT_EQUAL_INT(5, root->value);
  TEST_ASSERT_EQUAL_INT(4, root->left->value);
  TEST_ASSERT_EQUAL_INT(-1, root->left->left->value);
  TEST_ASSERT_NULL(root->right);

  // pre-order: 5, 4, -1
  printTree(&root);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_create_node);
  RUN_TEST(test_tree_insertion);
  RUN_TEST(test_find_value);
  RUN_TEST(test_find_min);
  RUN_TEST(test_find_max);
  RUN_TEST(test_erase_leaf_node);
  RUN_TEST(test_erase_node_w_one_child);
  RUN_TEST(test_erase_node_w_two_child);
  UNITY_END();

  return 0;
}
