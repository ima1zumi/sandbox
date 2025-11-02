#include <stdio.h>

int main(void) {
  int array[5];
  int *p1; // intへのポインタ型
  int *p2; // intへのポインタ型
  int *p3; // intへのポインタ型
  int i;

  for (i = 0; i < 5; i++) {
    array[i] = i;
  }

  // p = &array[0] : array[0] のアドレスをpに代入
  // p != &array[5] : pがarray[5]のアドレスと一致するまで
  for (p1 = &array[0]; p1 != &array[5]; p1++) {
    printf("%d\n", *p1);
  }

  // 書き換え版
  p2 = &array[0]; // p = array でもOK
  for (i = 0; i < 5; i++) {
    printf("%d\n", *(p2 + i));
  }

  // 書き換え版2
  p3 = array;
  for (i = 0; i < 5; i++) {
    printf("%d\n", p3[i]);
  }

  // 書き換え版3
  for (i = 0; i < 5; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
