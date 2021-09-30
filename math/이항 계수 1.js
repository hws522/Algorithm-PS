const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split(' ');

let [N, K] = input;

N = Number(N);
K = Number(K);

let resultN = 1;
let resultK = 1;

for(let i = N; i > N - K; i--){
  resultN *= i;
}

for(let i = K; i > 0; i--){
  resultK *= i
}

console.log(resultN / resultK);
