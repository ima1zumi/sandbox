typedef struct node {
  struct node *previous;
  struct node *next;
  char *string;
} Node;

typedef struct {
  Node *start;
} List;

int main() {
  return 0;
}
