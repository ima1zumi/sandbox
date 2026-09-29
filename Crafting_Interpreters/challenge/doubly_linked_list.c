#include <assert.h>
#include <stdlib.h>

typedef struct node {
  struct node *previous;
  struct node *next;
  char *string;
} Node;

typedef struct {
  Node *start;
} List;

void insert(List *list, char *string) {
  // nodeを作る。previousはNULL, nextはstart. stringはstring
  // list->startがNULLかどうか確認する
  // NULLでないときは、startのpreviousを作ったnodeに差し替える
  // startをnodeにする
}

int main() {
  List list = {0};
  char string;
 
  assert(list.start == NULL);
  insert(&list, &string);
  return 0;
}

