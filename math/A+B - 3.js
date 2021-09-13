const solution = (N, data) => {
    for(let i = 0; i < N; i++){
        console.log(data[i][0] + data[i][1])
    }
  };
  
  let fs = require('fs');
  let input = fs.readFileSync('/dev/stdin').toString().split('\n');
  
  const N = +input[0];
  const data = [];
  for (let i = 1; i < N + 1; i++) {
    data.push(input[i].split(' ').map((el) => +el));
  }
  
  solution(N, data);