#include <stdio.h>

// 配列を関数の引数として渡す

// 配列の先頭要素のポインタ、要素数
void func(int *array, int size) {
  int i;

  for (i = 0; i < size; i++) {
    printf("array[%d]...%d\n", i, array[i]); // arrayはただのポインタ. *(array + 1) と同じ
  }
}

int main(void) {
  int array[] = {1, 2, 3, 4, 5}; // 要素がintの配列
  printf("sizeof(array) = %zu\n", sizeof(array)); // %zuはsize_t型を表示するためのフォーマット指定子. zがsize_tのサイズにあわせる. uが符号なし整数
  printf("sizeof(array[0]) = %zu\n", sizeof(array[0]));

  func(array, sizeof(array) / sizeof(array[0]));

  return 0;
}
