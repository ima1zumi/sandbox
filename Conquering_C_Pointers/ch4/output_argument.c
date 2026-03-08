#include <stdio.h>

// funcの引数には、int型へのポインタ型の変数aと、double型へのポインタ型の変数bを受け取る
void func(int *a, double *b) {
  // a,bの値はアドレス
  *a = 5; // 間接演算子 * を使うことでaの値(アドレス)が指してる先の値を5に書き換える
  *b = 3.5; // 間接演算子 * を使うことでbの値(アドレス)が指してる先の値を3.5に書き換える
}

int main(void) {
  int a; // int型の変数aを宣言
  double b; // double型の変数bを宣言

  // &a, &b ... アドレス演算子&を使って取得したポインタ型の値(=アドレス)
  func(&a, &b);
  printf("a...%d, b...%f\n", a, b);

  return 0;
}
