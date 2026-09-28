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
}

int main() {
  List list = {0};
  char string;
 
  assert(list.start == NULL);
  insert(&list, &string);
  return 0;
}

