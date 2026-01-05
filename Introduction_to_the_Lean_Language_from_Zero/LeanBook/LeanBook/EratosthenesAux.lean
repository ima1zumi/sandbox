/-このコードは動かないよ-/
/-
  defコマンド
  1. 定義する関数の名前
  2. 丸括弧で引数とその型
  3. 返り値の型を指定
-/
def eratosthenesAux (n : Nat) : Array Bool := Id.run do
  let mut isPrime := Array.replicate (n + 1) true
  -- [true, true, ...]

  isPrime := isPrime.set! 0 false
  isPrime := isPrime.set! 1 false
  for p in [2 : n + 1] do
    -- p のとりうる数: 2, 3, 4, 5, 6
    if not isPrime[p]! then
      continue

    if p ^ 2 > n then
      break

    -- p =2の場合
    let mut q := p * p -- q = 4
    while q ≤ n do -- 4 <= 6なのでtrue
      isPrime := isPrime.set! q false
      q := q + p

  return isPrime

/-- エラトステネスの篩 -/
def eratosthenes (n : Nat) : Array Nat :=
  eratosthenesAux n
    |>.zipIdx
    |>.filterMap fun ⟨isPrime, i⟩ =>
      if isPrime then some i else none

#guard eratosthenes 10 = #[2, 3, 5, 7]
#eval eratosthenes 99

