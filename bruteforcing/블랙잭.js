const input = require("fs")
.readFileSync("input.txt")
.toString()
.trim()
.split('\n');

const testCase = input[0].split(' ').map(ele => Number(ele));
const cardNumber = testCase[0];
const cardSum = testCase[1];
const dataArr = input[1].split(' ').map(ele => Number(ele));

let result = 0;


for(let i = 0; i < cardNumber; i++){
  for(let j = i + 1; j < cardNumber; j++){
    for(let k = j + 1; k < cardNumber; k++){
      if(dataArr[i] + dataArr[j] + dataArr[k] <= cardSum && dataArr[i] + dataArr[j] + dataArr[k] > result) {
        result = dataArr[i] + dataArr[j] + dataArr[k];
      }
    }
  }
}

console.log(result);
