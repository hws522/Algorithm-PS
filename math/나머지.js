let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split('\n').map(ele => Number(ele));
let temp = [];
for(let i = 0; i < 10; i++){
  temp[i] = input[i] % 42;
}
let result = temp.filter((ele, idx) => temp.indexOf(ele) === idx);

console.log(result.length);