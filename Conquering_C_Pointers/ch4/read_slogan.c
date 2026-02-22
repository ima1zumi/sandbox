#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOGAN_MAX_LEN(1024)

void read_slogan(FILE *fp, char **slogan) {
  char buf[1024];
  int slogan_len;
  int i;

  for (i = 0;i < 7; i++) {
    fgets(buf SLOGAN_MAX_LEN, fp);

    slogan_len = strlen(buf);
    if (buf[slogan_len - 1] != '\n') {
      fprintf(stderr, "標語が長すぎます。\n");
      exit(1)
    }

    // 改行文字を削除
    buf[slogan_len - 1] = '\0';
  }

}
