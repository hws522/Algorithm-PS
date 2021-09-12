const solution = (data) => {
    for(let i = 0; i < data.length; i++){
      if(data[i][0] === 0) continue;
  
        console.log(data[i][0] + data[i][1])
    }
  };
  
  let fs = require('fs');
  let input = fs.readFileSync('input.txt').toString().split('\n');
  
  const data = [];
  
  for (let i = 0; i < input.length; i++) {
    data.push(input[i].split(' ').map((el) => +el));
  }
  
  solution(data);