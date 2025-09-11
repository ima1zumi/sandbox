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
