#include "linked-lists.h"
#include <stdio.h>

int main(void) {
  Node *list = NULL;
  list = insertNode(list, 10);
  list = insertNode(list, 5);
  list = insertNode(list, 15);

  printList(list);
  list = deleteNode(list, 5);
  printList(list);

  return 0;
}
