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

Node *find(List *list, char *string) {
  Node *n;

  return n; 
}

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
  char *string1 = "cat";
  char *string2 = "dog";
  Node *node;
 
  assert(list.start == NULL);
  insert(&list, string1);
  assert(list.start != NULL);
  assert(strcmp(list.start->string, string1) == 0);
  assert(list.start->previous == NULL);
  assert(list.start->next == NULL);
  insert(&list, string2);
  assert(strcmp(list.start->string, string2) == 0);
  assert(list.start->previous == NULL);
  assert(list.start->next != NULL);
  assert(strcmp(list.start->next->string, string1) == 0);
  assert(list.start->next->previous == list.start);
  assert(list.start->next->next == NULL);
  node = find(&list, string1);
  return 0;
}

