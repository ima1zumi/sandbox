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

// ノードの作成
Node* createNode(int key, int value) { // Node型のポインタを返す
  // ヒープ領域に確保し、関数が終わっても消えないようにする
  Node *node = (Node*)malloc(sizeof(Node)); // sizeof(Node)してNodeのサイズ計算、mallocでメモリ確保、mallocの返り値をNode*にキャスト
  node->key = key; // アロー演算子でメンバ変数に代入
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

// キャッシュの初期化
LRUCache* createCache(int capacity) {
  LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
  cache->capacity = capacity;
  cache->size = 0;
  cache->head = createNode(0, 0); // dummy
  cache->tail = createNode(0, 0); // dummy

  // headとtailをつなぐ
  cache->head->next = cache->tail;
  cache->tail->prev = cache->head;

  // ハッシュ(配列)をNULLで初期化
  for (int i = 0; i < MAX_KEY; i++) {
    cache->hash[i] = NULL;
  }

  return cache;
}

