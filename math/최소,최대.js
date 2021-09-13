let fs = require('fs');
let input = fs.readFileSync('input.txt').toString().split('\n');

const [T, numStr] = input;

const numList = numStr.split(' ').map((ele) => Number(ele));

const maxNum = numList.reduce((acc, cur) => (acc > cur ? acc : cur));
const minNum = numList.reduce((acc, cur) => (acc < cur ? acc : cur));

console.log(`${minNum} ${maxNum}`);