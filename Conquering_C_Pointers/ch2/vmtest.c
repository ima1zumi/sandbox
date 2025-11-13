#include <stdio.h>

int hoge;
int main(void) {
  char buf[256];

  printf("&hoge...%p\n", (void *)&hoge);

  printf("Input initial value.\n");
  fgets(buf, sizeof(buf), stdin); // fgetsとは
  sscanf(buf, "%d", hoge);  // sscanfとは

  for (;;) {
    printf("hoge..%d\n", hoge);

    // getcharで入力待ちの状態にする
    // リターンキーを叩く事にhogeの値が増加する

    getchar();
    hoge++;
  }
  return 0;
}

