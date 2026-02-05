#include <stdio.h>
#include <stdlib.h>

// ハッシュマップのサイズ
// defineは前処理、コンパイル前にソースコード内の特定の文字列を指定した文字列に単純に置換する
// マクロ
#define MAX_KEY 1024

// 双方向リストのノード
typedef struct Node { // 自分自身をメンバ変数の型として使うためにNodeを宣言
  int key;
  int value;
  struct Node *prev; // struct Nodeへのポインタ型prev
  struct Node *next;
} Node;

// LRUキャッシュ構造体
typedef struct {
  int capacity;        // キャッシュ容量
  int size;            // 現在の要素数
  Node *head;          // リストの先頭（最新）
  Node *tail;          // リストの末尾（最古）
  Node *hash[MAX_KEY]; // キーからノードへのポインタ配列
} LRUCache;

