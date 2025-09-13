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




