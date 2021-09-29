const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const result = input.map(ele => ele.split('').reverse());

const reverseNumber = result.map(ele => Number(ele.join('')))
const number = input.map(ele => Number(ele));

for(let i = 0; i < input.length - 1; i++){
  if(number[i] === reverseNumber[i]) console.log('yes');
  else console.log('no');
}