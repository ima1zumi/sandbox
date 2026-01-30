最近アクセスしたものにフラグを立ててGCのように管理する

PostgreSQL
Clock-Sweep アルゴリズム
https://ryuichi1208.hateblo.jp/entry/2025/02/11/165445
LRU(Least Recently Used)の改良版
参照された回数を持っていて、参照されるとカウンタをインクリメントする
リストがいっぱいになったら、時計回りに見ていき、カウンタが0のものを削除する
