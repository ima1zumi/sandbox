#include <stdio.h>
#include <stdbool.h>

#define NBUFFER 5 // バッファプールのサイズ
#define MAX_USAGE_COUNT 5

typedef struct {
  int buf_id;      // バッファID
  int content_id;  // 格納されているデータID
  int usage_count; // 利用頻度カウンタ
  int pin_coount;  // ピン留め数（0より大きい場合はEvict不可）
  bool is_valid;   // 有効なデータが入ってるか
};
