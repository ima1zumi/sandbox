#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node *previous;
  struct node *next;
  char *string;
} Node;

typedef struct {
  Node *start;
} List;

void insert(List *list, char *string) {
  Node *n = malloc(sizeof(Node));
  n->previous = NULL;
  n->next = list->start;
  n->string = strdup(string);

  if (list->start != NULL) {
    list->start->previous = n;
  }
  list->start = n;
}

int main() {
  List list = {0};
  char *string = "cat";
 
  assert(list.start == NULL);
  insert(&list, string);
  assert(list.start != NULL);
  assert(strcmp(list.start->string, string) == 0);
  assert(list.start->previous == NULL);
  assert(list.start->next == NULL);
  return 0;
}

