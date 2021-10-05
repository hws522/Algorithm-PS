/*
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
*/

const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split(' ')
.map(ele => Number(ele));

let [num1, num2] = input;
let N = num1;
let M = num2;

for(;;){
  let result = N % M;
  if(result !== 0){
      N = M;
      M = result;
    }
  else {
      break;
  }
}

console.log(M);
console.log(Number(num1 * num2 / M));