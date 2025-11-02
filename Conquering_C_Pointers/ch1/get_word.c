#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// memo;このFILE何？
// ファイルストリームを表すstructへのポインタ
int get_word(char *buf, int buf_size, FILE *fp) {
  int len;
  int ch;

  // 空白文字の読み飛ばし
  while ((ch = getc(fp)) != EOF && !isalnum(ch));

  // C言語では、if、for、whileなどの制御構文の直後に実行したい文が1つだけの場合、{}（ブロック、複合文）を省略できる
  if (ch == EOF)
    return EOF;

  // ここでchには最初の単語の文字が格納されている
  len = 0;
  // do-whileループ。中身が最低一回実行される
  do {
    buf[len] = ch;
    len++;
    if (len >= buf_size) {
      fprintf(stderr, "word too long.\n");
      exit(1);
    }
  } while ((ch = getc(fp)) != EOF && isalnum(ch)); // この後置while何？

  buf[len] = '\0';

  return len;
}

int main(void) {
  char buf[256];

  while (get_word(buf, 256, stdin) != EOF) {
    printf("<<%s>>]\\n", buf);
  }

  return 0;
}
