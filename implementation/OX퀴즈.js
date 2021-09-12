const solution = (testCase, data) => {
    let result;
    let cnt;
  
    for(let i = 0; i < testCase; i++){
      result = 0;
      cnt = 0;
  
      for(let j = 0; j < String(data[i]).length; j++){
        if(String(data[i])[j] === 'O'){
          result += ++cnt;
        }
        else if(String(data[i])[j] === 'X'){
          cnt = 0;
        }
      }
      console.log(result);
    }
  };
  
  let fs = require('fs');
  let input = fs.readFileSync('input.txt').toString().split('\n');
  
  const testCase = Number(input[0].split(' '));
  
  let data = [];
  for(let i = 1; i < input.length; i++){
    data.push(input[i].split(' '))
  }
  
  
  solution(testCase, data);