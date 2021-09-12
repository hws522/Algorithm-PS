let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().split(' ');

let aArr = [1,2,3,4,5,6,7,8];
let bArr = [8,7,6,5,4,3,2,1];

if(String(input).trim() === String(aArr)){
  console.log('ascending');
} 
else if(String(input).trim() === String(bArr)){
  console.log('descending');
} 
else{
  console.log('mixed');
}