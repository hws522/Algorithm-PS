const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const testCase = Number(input[0]);
const dataArr = input.slice(1).map(ele => Number(ele));
let totalArr = Array.from(Array(15), () => Array(15).fill(null));
let count = 0;

for(let i = 0; i < 15; i++){
  for(let j = 1; j < 15; j++){
    if(i === 0){
      totalArr[i][j] = j;
    }
    else{
      totalArr[i][j] = totalArr[i][j - 1] +totalArr[i - 1][j]; 
    }
  }
}

for(let i = 0; i < testCase; i++){
  console.log(totalArr[dataArr[count]][dataArr[count+1]]);
  count += 2;
}