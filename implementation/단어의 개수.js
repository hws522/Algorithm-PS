let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split(' ');

let result = 0;

if(input[0] === ''){
  result--;
};

result += input.length;

console.log(result);
