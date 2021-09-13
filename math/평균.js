let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().trim().split('\n');

const [T, result] = input;
const numArr = result.split(' ').map(ele => Number(ele));
const maxNum = numArr.reduce((acc, cur) => (acc > cur ? acc : cur));
let temp = 0;

const resultArr = numArr.map(ele => ele / maxNum * 100);


for(let i = 0; i < resultArr.length; i++){
  temp += resultArr[i];
}

console.log(temp / resultArr.length);