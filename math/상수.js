let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split(' ');

const [A, B] = input;

let reverseA = [];
let reverseB = [];

for(let i = 2; i >= 0; i--){
  reverseA += A[i];
  reverseB += B[i]; 
}

// console.log(A)
// console.log(B)
// console.log(reverseA)
// console.log(reverseB)

if(reverseA > reverseB) console.log(reverseA);
else console.log(reverseB);
