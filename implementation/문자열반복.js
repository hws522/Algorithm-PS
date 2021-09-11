let fs = require('fs');
let input = fs.readFileSync('dev/stdin').toString().split('\n');

let T = Number(input[0]);
let result = '';

for (let i = 1; i <= T; i++) {
  let count = Number(input[i].split(' ')[0]);  
  let text = input[i].split(' ')[1];  
  
  for (let j = 0; j < text.length; j++) {
    for (let k = 0; k < count; k++) {
      result += text[j];
    }
  }
  result += '\n';
}

console.log(result);