#include <assert.h>

typedef struct node {
  struct node *previous;
  struct node *next;
  char *string;
} Node;

typedef struct {
  Node *start;
} List;

int main() {
  List list = {0};
 
  assert(list.start == NULL);
  return 0;
}
