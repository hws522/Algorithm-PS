let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n').map(ele => Number(ele));
let result = Math.max(...input);

console.log(result);
console.log(input.indexOf(result) + 1);
