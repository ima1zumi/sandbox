#include <stdio.h>

// doubleのポインタ型を引数にうけとる
void get_xy(double *x_p, double *y_p) {
  // 仮引数x_p, y_pの値とアドレスを表示する
  printf("x_p..%p, y_p..%p\n", (void *)x_p, (void *)y_p);
  //=> x_p..0x16dc76750, y_p..0x16dc76748
  printf("&x_p..%p, &y_p..%p\n", (void *)&x_p, (void *)&y_p);
  //=> &x_p..0x16dc76708, &y_p..0x16dc76700

  // 引数で渡されたアドレスに値を格納する
  *x_p = 1.0;
  *y_p = 2.0;
}

int main(void) {
  double x;
  double y;

  // 変数x,yのアドレスを表示する
  printf("&x..%p, &y..%p\n", (void *)&x, (void *)&y);
  //=> &x..0x16dc76750, &y..0x16dc76748

  // 引数として変数x,yのアドレスを渡し、get_xy()側でそのアドレスに値を格納してもらう
  get_xy(&x, &y);

  // 受け取った値を表示する
  printf("x..%f, y..%f\n", x, y);
  // => x..1.000000, y..2.000000

  return 0;
}
