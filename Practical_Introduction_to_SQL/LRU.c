#include <stdio.h>
#include <stdlib.h>

// LRU(Least Recently Used)のサンプルコード
// キャッシュメモリの容量がいっぱいになったときに最も長い間参照されていないデータを破棄するアルゴリズム

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
Node *createNode(int key, int value) { // Node型のポインタを返す
  // ヒープ領域に確保し、関数が終わっても消えないようにする
  Node *node = (Node*)malloc(sizeof(Node)); // sizeof(Node)してNodeのサイズ計算、mallocでメモリ確保、mallocの返り値をNode*にキャスト
  node->key = key; // アロー演算子でメンバ変数に代入
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

// キャッシュの初期化
LRUCache *createCache(int capacity) {
  LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
  cache->capacity = capacity;
  cache->size = 0;
  cache->head = createNode(0, 0); // dummy
  cache->tail = createNode(0, 0); // dummy

  // headとtailをつなぐ
  cache->head->next = cache->tail;
  cache->tail->prev = cache->head;

  // ハッシュ(配列)をNULLで初期化
  // mallocで取ってきたデータは不定値が入っているので初期化する
  for (int i = 0; i < MAX_KEY; i++) {
    cache->hash[i] = NULL;
  }

  return cache;
}

// 引数で与えられたノードをリストから切り離す（削除はしない）
// Node a-b-cと連なっていたときにbのprev(a)のnextをcにして、bのnext(c)のprevをaにする
void removeNode(Node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

// 引数で与えられたノードをリストの先頭(headの直後)に挿入する
void addToHead(LRUCache *cache, Node *node) {
  node->next = cache->head->next;
  node->prev = cache->head;
  cache->head->next->prev = node;
  cache->head->next = node;
}

// データ取得
int get(LRUCache *cache, int key) {
  if (cache->hash[key] == NULL) {
    return -1; // 存在しない場合
  }

  Node *node = cache->hash[key]; //keyのNodeをcacheから取得

  // アクセスがあったので、現在の位置から抜いて先頭に移動
  removeNode(node);
  addToHead(cache, node);

  return node->value;
}

// データの追加、更新
void put(LRUCache *cache, int key, int value) {
  if (cache->hash[key] != NULL) {
    // すでに存在する場合は値を更新し、先頭へ移動
    Node *node = cache->hash[key]; // key位置のnodeを取得
    node->value = value; // valueを引数ので更新
    removeNode(node);
    addToHead(cache, node);
  } else {
    // 新規追加
    Node *newNode = createNode(key, value);
    cache->hash[key] = newNode;
    addToHead(cache, newNode);
    cache->size++;

    // 容量オーバー時の処理
    if (cache->size > cache->capacity) {
      // 末尾(tailの直前)が最も古いデータ
      Node *lru = cache->tail->prev;

      removeNode(lru);
      cache->hash[lru->key] = NULL;
      free(lru);

      cache->size--;
    }
  }
}

// デバッグ用にリストの中身を順に表示する
void printCache(LRUCache *cache) {
  Node *cur = cache->head->next;
  printf("Cache content (Most Recent -> Oldest): ");
  while (cur != cache->tail) {
    printf("[%d:%d] ", cur->key, cur->value);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  LRUCache *lru = createCache(2);

  put(lru, 1, 10);
  put(lru, 2, 20);
  printCache(lru);

  get(lru, 1);
  printCache(lru);

  put(lru, 3, 30);
  printCache(lru);

  printf("Get 2: %d\n", get(lru, 2)); // not found
  return 0;
}
