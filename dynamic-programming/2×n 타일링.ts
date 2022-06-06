/*
* 문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

* 입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

* 출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

let inputNumber: number = require("fs")
    .readFileSync("./input.txt")
    .toString()
    .trim();

let dp: number[] = [];

for (let i = 0; i < inputNumber; i++) {
    if (i === 0) dp[i] = 1;
    else if (i === 1) dp[i] = 2;
    else {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }
}

console.log(dp[inputNumber - 1])



/***********/
export { };
