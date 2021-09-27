const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const stringLength = Number(input[0]);
const lowerString = input[1];
const M = 1234567891;
let result = 0;
let pow = 1;


for(let i = 0; i < stringLength; i++){
  result += ((lowerString[i].charCodeAt() - 96) * pow);
  pow *= 31;
  pow %= M;
  result %= M;
}

console.log(result);