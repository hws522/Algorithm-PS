const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const number = Number(input[0]);
let sum = 1;

for(let i = 1;; i++){

  sum += 6 * i;

  if(number === 1) {
    console.log(1);
    return;
  }
  else if(number <= sum) {
    console.log(1 + i);
    return;
  }
}