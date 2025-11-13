#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...) {
  int i;
  va_list ap; // stdarg.hで定義されている型

  // 可変長引数では前から順番に型を指定しながら取得していく必要がある
  va_start(ap, format); // ポインタapを引数formatの次の位置に向ける
  for (i = 0; format[i] != '\0'; i++) {
    switch (format[i]) {
    case 's':
      printf("%s ", va_arg(ap, char *)); // va_arg() マクロにapと引数の型を指定すれば可変長部分を取り出せる
      break;
    case 'd':
      printf("%d ", va_arg(ap, int));
      break;
    default:
      assert(0);
    }
  }
  va_end(ap); // va_start()と対で書く
  putchar('\n');
}

int main(void) {
  tiny_printf("sdd", "result..", 3, 5);

  return 0;
}

