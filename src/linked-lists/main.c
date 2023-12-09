#include "linked-lists.h"
#include <stdio.h>

int main(void) {
  Node *list = NULL;
  insertNode(&list, 10);
  insertNode(&list, 5);
  insertNode(&list, 15);

  printList(list);
  //list = deleteNode(list, 5);
  //printList(list);

  return 0;
}
