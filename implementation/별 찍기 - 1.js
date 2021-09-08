let fs = require('fs');
let input = fs.readFileSync('dev/stdin').toString().split(' ');

let A = parseInt(input);
let star = '';

for(let i = 0; i < A; i++){
  star += '*';
  console.log(star);
}