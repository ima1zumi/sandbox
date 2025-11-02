#include <stdio.h>

int main(void) {
  int hoge = 5;
  int piyo = 10;
  int *hoge_p; // int型のポインタ型

  /* それぞれの変数のアドレスを表示する */
  // & はアドレス演算子. 変数に & 演算子を適用すると、その変数のアドレスが取得できる。そのアドレスのことを、その変数へのポインタと呼ぶ
  // ポインタの値をprintfで表示するには%pを使う. %pに対してはvoidへのポインタを指定することになっているので、void*にキャストする
  printf("&hoge...%p\n", (void*)&hoge);
  printf("&piyo...%p\n", (void*)&piyo);
  printf("&hoge_p...%p\n", (void*)&hoge_p);

  /* ポインタ変数hoge_pにhogeのアドレスを代入する */
  // ポインタ変数hoge_pが別の変数hogeへのポインタを保持しているとき、hoge_pがhogeを指している、という
  hoge_p = &hoge;
  printf("hoge_p...%p\n", (void *)hoge_p);

  /* hoge_pを経由してhogeの値を表示する */
  // * は間接演算子. ポインタに*をつけると指している先のものを表すようになる
  printf("*hoge_p...%d\n", *hoge_p);

  /* hoge_pを経由してhogeの値を変更する */
  *hoge_p = 10;
  printf("hoge...%d\n", hoge);

  return 0;
}
