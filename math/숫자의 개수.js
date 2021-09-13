let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split('\n');
let result = 1;

for(let i = 0; i < input.length; i++){
  result *= input[i];
}


let resultArr = String(result).split('')


let zeroToNine = new Array(10).fill(0);

for(let i = 0; i < resultArr.length; i++){
  zeroToNine[Number(resultArr[i])]++;
}

zeroToNine.forEach(ele => console.log(ele));