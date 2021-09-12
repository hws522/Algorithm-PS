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
    data.push(input[i].split(' ').map((el) => Number(el)));
  }
  
  solution(data);

  // Number 처리 하면 공백도 0 으로 바뀜.
  // 조건문에서 처리할 때, 공백과 0 값을 한번에 처리 가능.