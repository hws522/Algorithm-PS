const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

let number = Number(input[0]);
let threeNumber = 0;

for(let i = 0; ;i++){
  if(number % 5 === 0) return console.log((number / 5) + threeNumber);
  else if(number < 0) return console.log(-1);
  number -= 3;
  threeNumber++;
}