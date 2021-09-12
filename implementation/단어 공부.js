let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().toUpperCase().split('');
let result = input.filter((ele, idx) => input.indexOf(ele) === idx);
let resultArr = new Array(result.length).fill(0);

// console.log(input.length);
// console.log(input);
// console.log(result);

for(let i = 0; i < input.length; i++){
  resultArr[result.indexOf(input[i])]++;
}

// console.log(resultArr);

let max = resultArr[0];

for(let i = 0; i < resultArr.length; i++){
  if(max < resultArr[i]) max = resultArr[i];
}

if(resultArr.filter(ele => ele === max).length > 1) console.log('?');
else console.log(result[resultArr.indexOf(max)]);