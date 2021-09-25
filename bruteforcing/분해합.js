const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const number = Number(input[0]);
let resultArr = 0;

for(let i = number; i > 0; i--){
  let result = number;
  let numberArr = i.toString().split('').map(ele => Number(ele));
  
  numberArr.forEach(ele => result -= ele);

  if(i === result) resultArr = result;

}

console.log(resultArr);