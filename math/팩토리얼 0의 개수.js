/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/
const rl = require('readline').createInterface(process.stdin, process.stdout);

let input = 0,
  answer = 0;

rl.on('line', (line) => {
  input = +line;
}).on('close', () => {
  while (input >= 5) {
    answer += parseInt(input / 5);
    input /= 5;
  }
  console.log(answer);
});
