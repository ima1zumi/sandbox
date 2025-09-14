// comment

/*
  comment
*/

console.log(1);
console.log(0b1111); // 15
console.log(0o777); // 511
console.log(0xFFFF); // 65535
console.log(1.5);
console.log(.5);
console.log(2e3); // 2*10の3乗 = 2000
console.log(Number.MAX_SAFE_INTEGER); // 9007199254740991
console.log(1n); // BigInt
// 1.2n; // BigIntでは小数点は使えない
console.log(1_000_000); // 1000000

// Template Literal
`Template
Literal ${1 + 1}`; // Template\nLiteral 2

const foo = null;
console.log(foo); // null
// nullはリテラル
// undefinedはグローバル変数
// undefined = 1; // 代入できてしまうので注意

// オブジェクト
const obj = {};

// 演算子
console.log(1 + 2); // 1, 2は被演算子（オペランド）

// インクリメント演算子 ++ はオペランドの前後どちらに置くかによって挙動が変わる
// 副作用あり
let x = 1;
console.log(x++); // => 1
console.log(x);   // => 2

// 等価演算子
// ==, !== は暗黙的な型変換を行うので非推奨

// 分割代入
const array = [1, 2, 3];
const [first, second, third] = array;

// ES2020
// nullish coalescing operator (??)
// 左オペランドが null または undefined の場合に右オペランドを返す
console.log(null ?? 'default'); // 'default'
console.log(undefined ?? 'default'); // 'default'
console.log(0 ?? 'default'); // 0

const inputValue = 0;
const value = inputValue ?? 100; // 0. ここで||を使うと100になってしまう

// === 暗黙的な型変換 ===
// Falsyな値
// false, undefined, null, 0, 0n, NaN, ''

// 数値から文字列に変換するには String() を使う
console.log(String(123)); // '123'
"文字列" + String(Symbol("シンボル")); // '文字列Symbol(シンボル)'

// NaNは自分自身に等しくない
// NaNと何を計算してもNaN
console.log(NaN === NaN); // false
console.log(NaN + 1); // NaN

// === 関数と宣言 ===
// 関数宣言
// add: 関数名
// a, b: 仮引数
function add(a, b) {
  return a + b; // 戻り値
}

// 仮引数より呼び出し時の引数が少ない場合、余った仮引数にはundefinedが入る
// 仮引数より呼び出し時の引数が多い場合、余った引数は無視される
// ES2015: デフォルト引数を設定できる
function echo(x = 0) {
  return x;
}
console.log(echo()); // 0

// 可変長引数
// Rest Parameters (残余引数)
// 関数に渡された引数を配列として受け取る
functionfn(...args) {
  console.log(args);
}
fn(1, 2, 3); // [1, 2, 3]

// 配列を展開して関数に渡すSpread構文
function fn(x, y, z) {
  console.log(x, y, z);
}
const array2 = [1, 2, 3];
fn(...array2); // 1 2 3

// arguments
// 関数に渡された全ての引数を配列のようなオブジェクトで受け取る
// Arrow Functionでは使えないなどの制約があるので、Rest Parametersを使うことが推奨されている
function fn2() {
  console.log(arguments);
}

// 分割代入
// オブジェクトや配列からプロパティを取り出し、変数として定義し直す構文

function printUserId(user) {
  console.log(user.id);
}
const user = { id: 1, name: 'Alice' };
printUserId(user); // 1

// オブジェクトや配列から特定のプロパティ（または要素）を取り出して、個別の変数として宣言・代入するための便利なショートハンド
// 代入演算子（=）におけるオブジェクトの分割代入では、左辺に定義したい変数を定義し、右辺のオブジェクトから対応するプロパティを代入
const { id } = user;
console.log(id); // 1

// JavaScriptでは関数もオブジェクト
// ()をつけなければ関数オブジェクトを参照
// 関数が値として扱えることをファーストクラスファンクション（第一級関数）と呼ぶ
function fn() {
  console.log("fn");
}
const myFunc = fn;
myFunc();

// 関数式
// 関数を値として変数に代入する方法
// 関数式では関数名を省略できる(無名関数) 関数宣言では省略できない
const variable = function() {
};

function named() {
};

// 関数式でも関数名をつけることができる
// 関数名は関数内でのみ参照可能
const factorial = function fact(n) {
  if (n <= 1) {
    return 1;
  }
  return n * fact(n - 1);
}
console.log(factorial(5)); // 120

// Arrow Function
// 無名関数として定義される
const variable2 = (x, y) => {
  return x + y;
}

// 省略記法
// 仮引数が1つの場合、()を省略できる
// 関数本体が1行のreturn文のみの場合、{}とreturnを省略できる

// Arrow Functionの特徴
// 常に無名関数
// thisが静的に決定できる
// argumentsオブジェクトを持たない
// newできない
// Arrow Functionで書けるときはArrow Functionを使うことが推奨される

// コールバック関数
// 引数として渡される関数のこと
// コールバック関数を引数として扱う関数やメソッドのことを高階関数と呼ぶ
function higherOrderFunction(callback) {
  callback();
}

const array3 = [1, 2, 3];
const output = (value) => {
  console.log(value);
}
array3.forEach(output); // 1 2 3

// オブジェクトのプロパティである関数をメソッドと呼ぶ
// ES2015からオブジェクトリテラルでメソッドを定義する際にfunctionキーワードを省略できる
const obj2 = {
  value: 1,
  method() {
    return "this is method";
  }
};
console.log(obj2.method()); // this is method
