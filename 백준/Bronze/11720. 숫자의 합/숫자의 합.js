const solution = (T, data) => {
  let result = 0;
  data = data.split('').map(ele => Number(ele));
  for(let i = 0; i < T; i++){
    result += data[i];
  }
  console.log(result);
};

let fs = require('fs');
let input = fs.readFileSync('dev/stdin').toString().split('\n');
const [T, data] = input;


solution(T, data);
