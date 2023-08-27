# 알고리즘 문제 풀이

<br>
<br>
<br>
<br>

## 백준

- ### 한줄 입력 받을 때

  ```js
  const fs = require('fs');
  let input = fs.readFileSync('/dev/stdin').toString().split('\n');

  console.log(input);
  ```

  ```js
  const solution = (data) => {
    console.log(data);
  };

  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  let data = [];
  rl.on('line', function (line) {
    data.push(line);
    rl.close();
  }).on('close', function () {
    solution(data);
    process.exit();
  });
  ```

<br>

- ### 여러줄 입력 받을 때

  ```js
  const solution = (N, data) => {
    console.log(N);
    console.log(data);
  };

  let fs = require('fs');
  let input = fs.readFileSync('test').toString().split('\n');

  const N = +input[0];
  const data = [];
  for (let i = 1; i < N + 1; i++) {
    // 위에서 N을 받을떄 input[0]이 빠져나갔기 때문에 1~N을 받아야한다.
    data.push(input[i].split(' ').map((el) => +el));
  }

  solution(N, data);
  ```

  ```js
  const readline = require('readline');

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  let input = [];

  rl.on('line', function (line) {
    input.push(line);
  }).on('close', function () {
    console.log(input);
    process.exit();
  });
  ```
